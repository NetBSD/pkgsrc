# $NetBSD: Makefile,v 1.5 2008/03/01 12:08:44 obache Exp $
#

DISTNAME=	rabbit-0.5.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cozmixng.org/~rwiki/?cmd=view;name=Rabbit
COMMENT=	Application to do presentation with RD document

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.16.0:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool

USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rabbit bin/rabbit-theme-manager bin/rabrick
REPLACE_RUBY_DIRS=	${WRKSRC}/lib/rt

post-install:
	rm ${DESTDIR}${PREFIX}/bin/rabbit.bat

do-test:
	cd ${WRKSRC} && ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
