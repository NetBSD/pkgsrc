# $NetBSD: Makefile,v 1.8 1998/06/22 12:44:30 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       unix
PKGNAME=	icon-9.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.arizona.edu/icon/packages/unix/
ONLY_FOR_ARCHS=	i386

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=	true
ALL_TARGET=	Icon Icon-iconc

OPSYS!=         uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
