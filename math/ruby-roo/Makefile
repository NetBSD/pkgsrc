# $NetBSD: Makefile,v 1.4 2016/10/15 14:45:17 taca Exp $

DISTNAME=	roo-2.5.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roo-rb/roo
COMMENT=	Ruby library to read and write Spreadsheet Documents
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip-[0-9]*:../../archivers/ruby-zip

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
