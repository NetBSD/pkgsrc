# New ports collection makefile for:    mkisofs
# Version required:     1.11
# Date created:         07 Aug 1996
# Whom:                 jkh
#
# $NetBSD: Makefile,v 1.2 1997/10/29 12:26:14 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/28 11:30:44 joerg Exp
#

DISTNAME=       mkisofs-1.11
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

GNU_CONFIGURE=	yes
MAKE_FLAGS=	XCFLAGS='-c -I. ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"'`uname -s | tr [a-z] [A-Z]`'\"' -f
MAN8=		mkisofs.8

.include <bsd.port.mk>
