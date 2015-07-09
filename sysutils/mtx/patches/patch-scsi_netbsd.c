--- /dev/null	2015-07-08 16:44:57.000000000 +0200
+++ scsi_netbsd.c	2015-07-08 16:58:09.000000000 +0200
@@ -0,0 +1,159 @@
+/* Changes 2003 Steve Heck <steve.heck@am.sony.com>
+   Copyright 2007-2008 by Robert Nelson <robertn@the-nelsons.org>
+
+$Date: 2015/07/09 10:27:39 $
+$Revision: 1.1.1.1 $
+
+  This program is free software; you may redistribute and/or modify it under
+  the terms of the GNU General Public License Version 2 as published by the
+  Free Software Foundation.
+
+  This program is distributed in the hope that it will be useful, but
+  WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
+  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
+  for complete details.
+
+*/
+
+
+/* This is the SCSI commands for NetBSD using scsiio Interface. */
+
+DEVICE_TYPE SCSI_OpenDevice(char *DeviceName)
+{
+	int DeviceFD = open(DeviceName, O_RDWR, 0); 
+
+	if (DeviceFD < 0)
+		FatalError("cannot open SCSI device '%s' - %m\n", DeviceName);
+	return (DEVICE_TYPE) DeviceFD;
+}
+
+
+void SCSI_CloseDevice(char *DeviceName, DEVICE_TYPE DeviceFD)
+{
+	if (close(DeviceFD) < 0)
+		FatalError("cannot close SCSI device '%s' - %m\n", DeviceName);
+}
+
+
+#define HAS_SCSI_TIMEOUT
+
+static int timeout = 9 * 60;
+
+void SCSI_Set_Timeout(int to)
+{
+	timeout = to;
+}
+
+void SCSI_Default_Timeout(void)
+{
+	timeout = 9 * 60; /* the default */
+}
+
+#ifdef DEBUG
+int SCSI_DumpBuffer(int DataBufferLength, unsigned char *DataBuffer)
+{
+	int i, j;
+	j = 0;
+
+	for (i = 0; i < DataBufferLength; i++)
+	{
+		if (j == 25)
+		{
+			fprintf(stderr, "\n");
+			j = 0;
+		}
+
+		if (j == 0)
+		{
+			fprintf(stderr, "%04x:", i);
+		}
+
+		if (j > 0)
+		{
+			fprintf(stderr, " ");
+		}
+
+		fprintf(stderr, "%02x", (int)DataBuffer[i]);
+		j++;
+	}
+	fprintf(stderr, "\n");
+}
+#endif
+
+
+
+int SCSI_ExecuteCommand(DEVICE_TYPE DeviceFD,
+						Direction_T Direction,
+						CDB_T *CDB,
+						int CDB_Length,
+						void *DataBuffer,
+						int DataBufferLength,
+						RequestSense_T *RequestSense)
+{
+	int ioctl_result;
+	scsireq_t req;
+	
+
+#ifdef DEBUG_SCSI
+	fprintf(stderr,"------CDB--------\n");
+	SCSI_DumpBuffer(CDB_Length,(char *)CDB);
+#endif
+
+	memset(&req, 0, sizeof(scsireq_t));
+	memset(RequestSense, 0, sizeof(RequestSense_T));
+	switch (Direction)
+	{
+	case Input:
+		req.flags = SCCMD_READ;
+		if (DataBufferLength > 0)
+		{
+			memset(DataBuffer, 0, DataBufferLength);
+		}
+		break;
+
+	case Output:
+		req.flags = SCCMD_WRITE;
+		break;
+	}
+	/* Set timeout to 5 minutes. */
+#ifdef DEBUG_TIMEOUT
+	fprintf(stderr,"timeout=%d\n",timeout);
+	fflush(stderr);
+#endif
+
+	req.timeout = timeout * 1000;
+
+	memset(&req.cmd[0], 0, sizeof(req.cmd));
+        memcpy(&req.cmd[0], CDB, CDB_Length);
+	req.cmdlen = CDB_Length;
+
+	req.databuf = DataBuffer;
+	req.datalen = DataBufferLength;
+
+	req.senselen = SENSEBUFLEN;
+	req.senselen_used = 0;
+	ioctl_result = ioctl(DeviceFD, SCIOCCOMMAND, &req);
+
+	if (ioctl_result < 0)
+	{
+		perror("mtx: SCIOCCOMMAND");
+		return ioctl_result;
+	}
+	if (req.senselen_used > 0) {
+		memcpy(RequestSense, &req.sense[0],
+		    min(req.senselen_used, sizeof(RequestSense_T)));
+	}
+
+	if (req.retsts != SCCMD_OK)
+	{
+		return -1;
+	}
+#ifdef DEBUG_SCSI
+	if (Direction==Input)
+	{
+		fprintf(stderr,"--------input data-----------\n");
+		SCSI_DumpBuffer(DataBufferLength,DataBuffer);
+	}
+#endif
+	return 0;
+}
