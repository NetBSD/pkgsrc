# $NetBSD: Makefile,v 1.1 2025/02/07 15:58:35 pho Exp $

DISTNAME=	buildsystem-1.10
PKGNAME=	netsurf-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://source.netsurf-browser.org/buildsystem.git
COMMENT=	Makefiles shared by NetSurf projects
LICENSE=	mit

NO_BUILD=	yes
USE_TOOLS+=	bash:run gmake perl:run

REPLACE_BASH+=	citools/jenkins-build.sh
REPLACE_PERL+=	testtools/testrunner.pl

.include "../../mk/bsd.pkg.mk"
