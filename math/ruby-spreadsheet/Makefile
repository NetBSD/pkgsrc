# $NetBSD: Makefile,v 1.38 2015/03/15 17:25:56 hiramatsu Exp $
#

DISTNAME=	spreadsheet-1.0.3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spreadsheet.rubyforge.org/
COMMENT=	Ruby Spreadsheet Library to read and write Spreadsheet Documents
LICENSE=	gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-ole>=1.0:../../devel/ruby-ole

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
