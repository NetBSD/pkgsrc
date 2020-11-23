/* $NetBSD: nopop3d.c,v 1.2 2020/11/23 18:17:22 schmonz Exp $ */

#include <stdlib.h>
#include "commands.h"
#include "sig.h"
#include "substdio.h"
#include "readwrite.h"
#include "timeoutread.h"
#include "timeoutwrite.h"

void die() { exit(0); }

int saferead(fd,buf,len) int fd; char *buf; int len;
{
  int r;
  r = timeoutread(1200,fd,buf,len);
  if (r <= 0) die();
  return r;
}

int safewrite(fd,buf,len) int fd; char *buf; int len;
{
  int r;
  r = timeoutwrite(1200,fd,buf,len);
  if (r <= 0) die();
  return r;
}

char ssoutbuf[1024];
substdio ssout = SUBSTDIO_FDBUF(safewrite,1,ssoutbuf,sizeof ssoutbuf);

char ssinbuf[128];
substdio ssin = SUBSTDIO_FDBUF(saferead,0,ssinbuf,sizeof ssinbuf);

void err_unimpl(arg) char *arg; {
  substdio_putsflush(&ssout,"-ERR unimplemented\r\n");
}

void okay(arg) char *arg;
{
  substdio_putsflush(&ssout,"+OK \r\n");
}

void pop3_list(arg) char *arg;
{
  substdio_putsflush(&ssout,"+OK \r\n.\r\n");
}

void pop3_stat(arg) char *arg;
{
  substdio_putsflush(&ssout,"+OK 0 0\r\n");
}

void pop3_quit(arg) char *arg;
{
  okay();
  die();
}

struct commands pop3commands[] = {
  { "quit", pop3_quit, 0 }
, { "stat", pop3_stat, 0 }
, { "list", pop3_list, 0 }
, { "noop", okay, 0 }
, { 0, err_unimpl, 0 }
} ;

void main(argc,argv)
int argc;
char **argv;
{
  sig_alarmcatch(die);
  sig_pipeignore();
 
  okay(0);
  commands(&ssin,pop3commands);
  die();
}
