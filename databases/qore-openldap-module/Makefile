# $NetBSD: Makefile,v 1.17 2023/10/24 22:08:39 wiz Exp $

DISTNAME=	qore-openldap-module-1.2.3
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-openldap
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
COMMENT=	Openldap module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
