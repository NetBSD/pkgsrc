# $NetBSD: Makefile,v 1.9 2013/03/14 13:42:57 obache Exp $

DISTNAME=	pkg-config-1.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBYGEMS}
EXTRACT_SUFX=	.gem

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/rcairo/pkg-config
COMMENT=	pkg-config implemented by pure Ruby
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	${RUBY_PKGPREFIX}-gnome2-glib<0.90.0

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

#do-test:
#		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
