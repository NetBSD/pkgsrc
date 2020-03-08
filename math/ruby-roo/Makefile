# $NetBSD: Makefile,v 1.8 2020/03/08 16:06:05 taca Exp $

DISTNAME=	roo-2.8.3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roo-rb/roo
COMMENT=	Ruby library to read and write Spreadsheet Documents
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.3.0:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
