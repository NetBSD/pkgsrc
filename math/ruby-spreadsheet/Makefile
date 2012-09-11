# $NetBSD: Makefile,v 1.14 2012/09/11 23:04:33 asau Exp $
#

DISTNAME=	spreadsheet-0.7.3
CATEGORIES=	math

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://spreadsheet.rubyforge.org/
COMMENT=	Ruby Spreadsheet Library to read and write Spreadsheet Documents
LICENSE=	gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-ole>=1.0:../../devel/ruby-ole

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
