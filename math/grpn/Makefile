# $NetBSD: Makefile,v 1.70 2025/12/26 10:16:50 wiz Exp $

DISTNAME=	grpn_1.3.3-1
PKGNAME=	grpn-1.3.3
PKGREVISION=	39
CATEGORIES=	math
#MASTER_SITES=	http://lashwhip.com/grpn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/utopiabound/grpn
COMMENT=	Graphical reverse polish notation (RPN) calculator

BUILD_TARGET=	grpn
USE_TOOLS+=	mkdirhier pkg-config
WRKSRC=		${WRKDIR}/grpn-1.3.3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
