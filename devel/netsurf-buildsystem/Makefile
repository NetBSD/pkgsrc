# $NetBSD: Makefile,v 1.2 2026/01/12 06:47:07 wiz Exp $

DISTNAME=	buildsystem-1.10
PKGNAME=	netsurf-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/
COMMENT=	Makefiles shared by NetSurf projects
LICENSE=	mit

NO_BUILD=	yes
USE_TOOLS+=	bash:run gmake perl:run

REPLACE_BASH+=	citools/jenkins-build.sh
REPLACE_PERL+=	testtools/testrunner.pl

.include "../../mk/bsd.pkg.mk"
