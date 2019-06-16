# $NetBSD: Makefile,v 1.175 2019/06/16 16:39:57 tsutsui Exp $
#

DISTNAME=	mikutter.3.9.0-alpha1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-//:S/./-/}
CATEGORIES=	net
MASTER_SITES=	https://mikutter.hachune.net/bin/

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://mikutter.hachune.net/
COMMENT=	Simple, powerful, and moeful twitter client
LICENSE=	mit AND cc-by-sa-v3.0

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-pluggaloid>=1.2.0:../../net/ruby-pluggaloid
DEPENDS+=	${RUBY_PKGPREFIX}-diva>=1.0.0:../../devel/ruby-diva
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=3.3.6:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.2.9:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.5.4:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.6.0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-memoist>=0.16.0:../../devel/ruby-memoist
DEPENDS+=	${RUBY_PKGPREFIX}-typed-array>=0.1.2:../../misc/ruby-typed-array
DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.0.0:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-delayer-deferred>=2.1.0:../../devel/ruby-delayer-deferred
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient-[0-9]*:../../www/ruby-httpclient
DEPENDS+=	${RUBY_PKGPREFIX}-moneta>=0.7:../../databases/ruby-moneta
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-text>=3.0.0:../../net/ruby-twitter-text

WRKSRC=		${WRKDIR}/mikutter
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

REPLACE_RUBY=	mikutter.rb
REPLACE_RUBY_DIRS=	core

INSTALLATION_DIRS+=	bin share/doc/mikutter share/applications share/mikutter

do-build:
	${RM} -rf ${WRKSRC}/vendor
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/desktop.in > ${WRKDIR}/desktop
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/mikutter.sh.in > ${WRKDIR}/mikutter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mikutter.rb ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/Gemfile ${DESTDIR}${PREFIX}/share/mikutter
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' core plugin ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mikutter
	${INSTALL_SCRIPT} ${WRKDIR}/mikutter.sh ${DESTDIR}${PREFIX}/bin/mikutter
	${INSTALL_DATA} ${WRKDIR}/desktop ${DESTDIR}${PREFIX}/share/applications/mikutter.desktop

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
