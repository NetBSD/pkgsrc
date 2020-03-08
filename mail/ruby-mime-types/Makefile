# $NetBSD: Makefile,v 1.17 2020/03/08 16:04:22 taca Exp $

DISTNAME=	mime-types-3.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mime-types/ruby-mime-types/
COMMENT=	Definition of MIME types for Ruby
LICENSE=	ruby-license OR artistic OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types-data>=3.2015<4:../../mail/ruby-mime-types-data

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
