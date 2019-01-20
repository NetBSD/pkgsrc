# $NetBSD: Makefile,v 1.6 2019/01/20 14:10:29 taca Exp $

DISTNAME=	roo-2.8.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roo-rb/roo
COMMENT=	Ruby library to read and write Spreadsheet Documents
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip-[0-9]*:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
