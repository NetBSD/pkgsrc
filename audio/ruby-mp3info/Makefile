# $NetBSD: Makefile,v 1.6 2012/10/02 23:48:08 asau Exp $
#

DISTNAME=	ruby-mp3info-0.6.13
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	audio
MASTER_SITES=	http://rubyforge.org/frs/download.php/57443/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ruby-mp3info.rubyforge.org/
COMMENT=	Pure-ruby library for informations and tags on mp3 files
LICENSE=	ruby-license

USE_LANGUAGES=	# none
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

CONFIGURE_ARGS+=	--site-ruby=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
