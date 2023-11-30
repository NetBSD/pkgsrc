# $NetBSD: Makefile,v 1.5 2023/11/30 06:08:51 adam Exp $

DISTNAME=	olm-3.2.16
CATEGORIES=	security
MASTER_SITES=	https://gitlab.matrix.org/matrix-org/olm/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.matrix.org/matrix-org/olm
COMMENT=	Implementation of the Double Ratchet cryptographic ratchet
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	olm.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
