# $NetBSD: Makefile,v 1.10 1998/08/20 15:17:05 tsarna Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       unix
PKGNAME=	icon-9.3.1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=	.tgz
ONLY_FOR_ARCHS=	alpha i386

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.arizona.edu/icon/index.htm

DIST_SUBDIR=	icon
NO_WRKSUBDIR=	true
ALL_TARGET=	Icon Icon-iconc

OPSYS!=         uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

MAN1=		icon.1

.include "../../mk/bsd.pkg.mk"
