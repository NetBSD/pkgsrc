# $NetBSD: Makefile,v 1.6 1998/06/22 13:09:51 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/28 11:30:44 joerg Exp
#

DISTNAME=       mkisofs-1.11
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
MAKE_FLAGS=	XCFLAGS='-c -I. ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"'`uname -s | ${TR} [a-z] [A-Z]`'\"'

.include "../../mk/bsd.pkg.mk"
