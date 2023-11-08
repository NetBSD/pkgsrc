# $NetBSD: Makefile,v 1.11 2023/11/08 13:20:28 wiz Exp $
#

DISTNAME=	kdsoap-1.9.1
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_PROJECT=	KDSoap
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KDAB/KDSoap
COMMENT=	Qt-based client-side and server-side SOAP component
LICENSE=	gnu-agpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
