# $NetBSD: Makefile,v 1.1.1.1 2011/02/15 10:47:20 obache Exp $
#

DISTNAME=	ruby-mp3info-0.6.13
CATEGORIES=	audio
MASTER_SITES=	http://rubyforge.org/frs/download.php/57443/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/frs/download.php/57443/
COMMENT=	Pure-ruby library for informations and tags on mp3 files
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

CONFIGURE_ARGS+=	--site-ruby=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
