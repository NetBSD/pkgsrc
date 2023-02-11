# $NetBSD: Makefile,v 1.11 2023/02/11 13:50:38 taca Exp $

DISTNAME=	roo-2.10.0
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
