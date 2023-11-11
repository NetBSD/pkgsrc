# $NetBSD: Makefile,v 1.4 2023/11/11 14:01:07 taca Exp $

DISTNAME=	rex-ole-0.1.8
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-ole
COMMENT=	Rex Library for reading/writing OLE files and streams
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
