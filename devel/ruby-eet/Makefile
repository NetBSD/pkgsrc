# $NetBSD: Makefile,v 1.7 2010/09/10 05:33:12 taca Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files
LICENSE=	mit

RUBY_VERSION_SUPPORTED= 18

USE_RAKE=	YES
USE_TOOLS+=	pkg-config

.include "../../devel/eet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${RAKE}

do-install:
	cd ${WRKSRC} && ${RAKE} install

.include "../../mk/bsd.pkg.mk"
