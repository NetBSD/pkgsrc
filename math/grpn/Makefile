# $NetBSD: Makefile,v 1.35 2012/10/02 17:11:31 tron Exp $
#

DISTNAME=	grpn_1.3.3-1
PKGNAME=	grpn-1.3.3
PKGREVISION=	6
CATEGORIES=	math
#MASTER_SITES=	http://lashwhip.com/grpn/
MASTER_SITES=	http://www.getreu.net/public/downloads/software/grpn/grpn-1.3.3/

MAINTAINER=	dmcmahill@NetBSD.org
# the original gtk1 version
#HOMEPAGE=	http://lashwhip.com/grpn.html
HOMEPAGE=	http://www.getreu.net/
COMMENT=	Graphical reverse polish notation (RPN) calculator

BUILD_TARGET=	grpn
USE_TOOLS+=	mkdirhier pkg-config
WRKSRC=		${WRKDIR}/grpn-1.3.3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
