# $NetBSD: Makefile,v 1.5 2025/02/23 14:35:29 taca Exp $

DISTNAME=	rex-ole-0.1.9
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-ole
COMMENT=	Rex Library for reading/writing OLE files and streams
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
