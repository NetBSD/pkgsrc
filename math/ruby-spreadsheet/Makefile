# $NetBSD: Makefile,v 1.7 2011/09/08 10:57:42 obache Exp $
#

DISTNAME=	spreadsheet-0.6.5.9
CATEGORIES=	math

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://spreadsheet.rubyforge.org/
COMMENT=	Ruby Spreadsheet Library to read and write Spreadsheet Documents
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-ole>=1.0:../../devel/ruby-ole

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
