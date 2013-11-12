# $NetBSD: Makefile,v 1.28 2013/11/12 11:43:23 obache Exp $
#

DISTNAME=	spreadsheet-0.9.2
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
