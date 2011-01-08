/* --------------------------------------------------------------------------

   MusicBrainz -- The Internet music metadatabase

   Copyright (C) 2000 Robert Kaye
   Copyright (C) 1999 Marc E E van Woerkom
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <netinet/in.h>

#include "mb.h"
#include "diskid.h"
#include "config.h"


MUSICBRAINZ_DEVICE DEFAULT_DEVICE = "/dev/cd0";


int ReadTOCHeader(int fd, 
                  int& first, 
                  int& last)
{
   struct ioc_toc_header th;

   int ret = ioctl(fd,
                   CDIOREADTOCHEADER, 
                   &th);

   if (!ret)
   {
      first = th.starting_track;
      last  = th.ending_track;
   }

   return ret;
}


int ReadTOCEntry(int fd, 
                 int track, 
                 int& lba)
{
    struct ioc_read_toc_entry te;

    te.starting_track = (u_char) track;
    te.address_format = CD_LBA_FORMAT;   // experiment and cdio.h say 
                                         // lbas are given in network order!
    
    struct cd_toc_entry cte;

    te.data = &cte;
    te.data_len = sizeof(cd_toc_entry);
    
    int ret = ioctl(fd, 
                    CDIOREADTOCENTRYS, 
                    &te);

    if (!ret) {
        assert(te.address_format == CD_LBA_FORMAT);

        lba = ntohl(te.data->addr.lba);  // network to host order (long)
    }

    return ret;
}


bool DiskId::ReadTOC(MUSICBRAINZ_DEVICE device, 
                     MUSICBRAINZ_CDINFO& cdinfo)
{
   int fd;
   int first;
   int last;
   int lba;
   int i;

   if (device == NULL)
   {
       device = DEFAULT_DEVICE;
   }

   fd = open(device, O_RDONLY);
   if (fd < 0)
   {
       char err[256];

       sprintf(err, "Cannot open '%s'", device);
       ReportError(err);

       return false;
   }

   // Initialize cdinfo to all zeroes.
   memset(&cdinfo, 0, sizeof(MUSICBRAINZ_CDINFO));

   // Find the number of the first track (usually 1) and the last track.
   if (ReadTOCHeader(fd, first, last))
   {
      ReportError("Cannot read table of contents.");
      close(fd);
      return false;
   }

   // Do some basic error checking.
   if (last==0)
   {
      ReportError("This disk has no tracks.");
      close(fd);	
      return false;
   }


   // Now, for every track, find out the block address where it starts.
   for (i = first; i <= last; i++)
   {
      ReadTOCEntry(fd, i, lba);
      cdinfo.FrameOffset[i] = lba + 150;
   }


   // Get the logical block address (lba) for the end of the audio data.
   // The "LEADOUT" track is the track beyond the final audio track
   // so we're looking for the block address of the LEADOUT track.

   int CDROM_LEADOUT = last + 1;
   ReadTOCEntry(fd, CDROM_LEADOUT, lba);
   cdinfo.FrameOffset[0] = lba + 150;

   cdinfo.FirstTrack = first;
   cdinfo.LastTrack = last;

   close(fd);

   return true;
}
