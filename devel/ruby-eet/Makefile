# $NetBSD: Makefile,v 1.9 2011/03/21 08:56:40 obache Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_VERSION_SUPPORTED= 18

USE_RAKE=	YES
USE_TOOLS+=	pkg-config

.include "../../devel/eet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${RAKE} install

.include "../../mk/bsd.pkg.mk"
