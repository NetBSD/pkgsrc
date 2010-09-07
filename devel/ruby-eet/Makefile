# $NetBSD: Makefile,v 1.6 2010/09/07 17:20:25 taca Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files

BUILD_DEPENDS+=	rake-[0-9]*:../../devel/rake

RUBY_VERSION_SUPPORTED= 18

USE_TOOLS+=	pkg-config

.include "../../devel/eet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/rake ext

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/rake install

.include "../../mk/bsd.pkg.mk"
