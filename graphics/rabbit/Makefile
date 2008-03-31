# $NetBSD: Makefile,v 1.8 2008/03/31 15:26:34 jlam Exp $
#

DISTNAME=	rabbit-0.5.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cozmixng.org/~rwiki/?cmd=view;name=Rabbit
COMMENT=	Application to do presentation with RD document

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.16.0:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-rttool>=1.0.2:../../textproc/ruby-rttool

USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rabbit bin/rabbit-theme-manager bin/rabrick

pre-configure:
	rm -rf ${WRKSRC}/lib/rt

post-install:
	rm ${DESTDIR}${PREFIX}/bin/rabbit.bat

do-test:
	cd ${WRKSRC} && ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
