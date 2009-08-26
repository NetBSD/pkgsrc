# $NetBSD: Makefile,v 1.3 2009/08/26 19:57:23 sno Exp $

DISTNAME=	ruby-eet-0.1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://code-monkey.de/pub/ruby-eet/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code-monkey.de/pages/ruby-eet
COMMENT=	Ruby module to read and write EET files

BUILD_DEPENDS+=	rake-[0-9]*:../../devel/rake

USE_TOOLS+=	pkg-config

.include "../../devel/eet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/rake ext

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/rake install

.include "../../mk/bsd.pkg.mk"
