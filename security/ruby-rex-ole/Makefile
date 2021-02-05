# $NetBSD: Makefile,v 1.3 2021/02/05 15:17:20 taca Exp $

DISTNAME=	rex-ole-0.1.7
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-ole
COMMENT=	Rex Library for reading/writing OLE files and streams
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
