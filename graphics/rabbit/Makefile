# $NetBSD: Makefile,v 1.1.1.1 2007/06/04 04:13:53 obache Exp $
#

DISTNAME=	rabbit-0.5.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cozmixng.org/~rwiki/?cmd=view;name=Rabbit
COMMENT=	Application to do presentation with RD document

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.16.0:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool

USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rabbit bin/rabbit-theme-manager bin/rabrick

do-test:
	cd ${WRKSRC:Q} && ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
