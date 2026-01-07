# $NetBSD: Makefile,v 1.31 2026/01/07 08:48:45 wiz Exp $

DISTNAME=	qore-xmlsec-module-1.0.0
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
GITHUB_PROJECT=	module-xmlsec
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	XMLSec module for Qore
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	native

CMAKE_USE_GNU_INSTALL_DIRS=	no

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
