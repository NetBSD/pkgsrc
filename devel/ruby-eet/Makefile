# $NetBSD: Makefile,v 1.25 2026/11/17 13:57:59 wiz Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	# ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files
LICENSE=	mit

USE_TOOLS+=	pkg-config

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE} -j ${_MAKE_JOBS_N}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${RAKE} -j ${_MAKE_JOBS_N} install

.include "../../lang/ruby/modules.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
