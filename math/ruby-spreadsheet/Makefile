# $NetBSD: Makefile,v 1.1.1.1 2011/04/13 13:17:00 obache Exp $
#

DISTNAME=	spreadsheet-0.6.5.3
CATEGORIES=	math
MASTER_SITES=	http://rubyforge.org/frs/download.php/74536/

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
