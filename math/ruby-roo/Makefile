# $NetBSD: Makefile,v 1.2 2016/01/12 09:40:55 wiz Exp $

DISTNAME=	roo-2.3.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roo-rb/roo
COMMENT=	Ruby library to read and write Spreadsheet Documents
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip-[0-9]*:../../archivers/ruby-zip

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
