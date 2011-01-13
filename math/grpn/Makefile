# $NetBSD: Makefile,v 1.26 2011/01/13 13:38:41 wiz Exp $
#

DISTNAME=	grpn
PKGNAME=	grpn-1.2
DIST_SUBDIR=	grpn-1.2
PKGREVISION=	4
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
