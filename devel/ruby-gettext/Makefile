# $NetBSD: Makefile,v 1.4 2008/02/12 03:01:03 obache Exp $

DISTNAME=	ruby-gettext-package-1.10.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-(.*)-package/\1/}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/22478/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://gettext.rubyforge.org/
COMMENT=	Ruby L10n library like as GNU GetText

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_SETUP=		yes
RUBY_HAS_ARCHLIB=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
