# $NetBSD: Makefile,v 1.6 2025/08/20 11:34:46 wiz Exp $
#

DISTNAME=	mppenc-1.16
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	Musepack encoder
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
