# $NetBSD: Makefile,v 1.23 2010/06/13 22:44:56 wiz Exp $
#

DISTNAME=	grpn
PKGNAME=	grpn-1.2
DIST_SUBDIR=	grpn-1.2
PKGREVISION=	1
CATEGORIES=	math
#MASTER_SITES=	http://lashwhip.com/grpn/
MASTER_SITES=	http://www.getreu.net/public/downloads/

MAINTAINER=	dmcmahill@NetBSD.org
# the original gtk1 version
#HOMEPAGE=	http://lashwhip.com/grpn.html
HOMEPAGE=	http://www.getreu.net/
COMMENT=	Graphical reverse polish notation (RPN) calculator

BUILD_TARGET=	grpn
USE_TOOLS+=	mkdirhier pkg-config
WRKSRC=		${WRKDIR}/grpn-1.2
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
