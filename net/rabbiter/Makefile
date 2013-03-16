# $NetBSD: Makefile,v 1.1 2013/03/16 13:28:10 obache Exp $
#

DISTNAME=	rabbiter-2.0.0
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_RUBYGEMS}
EXTRACT_SUFX=	.gem

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rabbit-shocker.org/en/rabbiter/
COMMENT=	Twitter client for Rabbit
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-rabbit>=2.0.0:../../graphics/rabbit
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gio>=1.1.4:../../devel/ruby-gnome2-gio
DEPENDS+=	${RUBY_PKGPREFIX}-twitter_oauth-[0-9]*:../../security/ruby-twitter_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream>=0.1.6:../../net/ruby-twitter-stream
CONFLICTS+=	${RUBY_PKGPREFIX}-rabbit<2.0.0

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
