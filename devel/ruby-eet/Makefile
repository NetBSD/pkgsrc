# $NetBSD: Makefile,v 1.21 2020/01/18 21:49:15 jperkin Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files
LICENSE=	mit

USE_TOOLS+=	pkg-config

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${RAKE} install

.include "../../lang/ruby/modules.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
