# $NetBSD: Makefile,v 1.1.1.1 2007/05/26 06:21:30 obache Exp $

DISTNAME=	ruby-gettext-package-1.9.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-package//}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/16681/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://gettext.rubyforge.org/
COMMENT=	Ruby L10n library like as GNU GetText

USE_RUBY_SETUP=		yes
RUBY_HAS_ARCHLIB=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
