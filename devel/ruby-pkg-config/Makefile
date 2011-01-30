# $NetBSD: Makefile,v 1.3 2011/01/30 12:10:30 obache Exp $

DISTNAME=	pkg-config-1.0.8
CATEGORIES=	devel
MASTER_SITES=	http://rubyforge.org/frs/download.php/74122/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/rcairo/pkg-config
COMMENT=	pkg-config implemented by pure Ruby
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	${RUBY_PKGPREFIX}-gnome2-glib<0.90.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes

#do-test:
#		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
