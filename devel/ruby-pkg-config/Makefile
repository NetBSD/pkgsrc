# $NetBSD: Makefile,v 1.6 2012/02/01 12:32:12 obache Exp $

DISTNAME=	pkg-config-1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://rubygems.org/gems/ \
		http://gems.rubyforge.org/gems/
EXTRACT_SUFX=	.gem

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/rcairo/pkg-config
COMMENT=	pkg-config implemented by pure Ruby
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	${RUBY_PKGPREFIX}-gnome2-glib<0.90.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_SETUP=		yes

SUBST_CLASSES+=		vsetup
SUBST_STAGE.vsetup=	pre-configure
SUBST_FILES.vsetup=	setup.rb
SUBST_SED.vsetup=	-e "s|'sitedir'|'vendordir'|g"
SUBST_SED.vsetup+=	-e "s|'sitelibdir'|'vendorlibdir'|g"
SUBST_SED.vsetup+=	-e 's|"sitelibdir"|"vendorlibdir"|g'
SUBST_SED.vsetup+=	-e 's|/site_ruby/|/vendor_ruby/|g'
SUBST_MESSAGE.vsetup=	Fixing setup.rb to use `vendor'.

#do-test:
#		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
