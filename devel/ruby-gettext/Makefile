# $NetBSD: Makefile,v 1.3 2007/08/06 15:42:30 obache Exp $

DISTNAME=	ruby-gettext-package-1.10.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-(.*)-package/\1/}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/22478/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://gettext.rubyforge.org/
COMMENT=	Ruby L10n library like as GNU GetText

USE_RUBY_SETUP=		yes
RUBY_HAS_ARCHLIB=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
