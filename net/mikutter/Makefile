# $NetBSD: Makefile,v 1.70 2013/08/05 12:46:52 obache Exp $
#

DISTNAME=	mikutter.0.2.2.1318
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	http://mikutter.hachune.net/bin/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mikutter.hachune.net/
COMMENT=	Simple, powerful, and moeful twitter client
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

RUBY_VERSION_SUPPORTED=	193 200

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${RUBY_PKGPREFIX}-hmac>=0.4.0:../../security/ruby-hmac
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=1.2.5:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-rcairo>=1.10.0:../../graphics/ruby-rcairo
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-memoize>=1.3.1:../../devel/ruby-memoize
DEPENDS+=	${RUBY_PKGPREFIX}-bsearch>=1.5:../../devel/ruby-bsearch
DEPENDS+=	${RUBY_PKGPREFIX}-addressable-[0-9]*:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-typed-array-[0-9]*:../../misc/ruby-typed-array
#DEPENDS+=	${RUBY_PKGPREFIX}-test-unit-[0-9]*:../../devel/ruby-test-unit
# notify-send
DEPENDS+=	{libnotify-[0-9]*,libnotify07-[0-9]*}:../../sysutils/libnotify

WRKSRC=		${WRKDIR}/mikutter
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

REPLACE_RUBY=	mikutter.rb devel/makechi.rb
REPLACE_RUBY_DIRS=	core
.include "../../lang/ruby/replace.mk"

INSTALLATION_DIRS+=	bin share/doc/mikutter share/applications share/mikutter

do-build:
	cd ${WRKSRC}/devel && \
		${RM} -rf debian
	${RM} -rf ${WRKSRC}/vendor
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/desktop.in > ${WRKDIR}/desktop
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/mikutter.sh.in > ${WRKDIR}/mikutter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mikutter.rb ${DESTDIR}${PREFIX}/share/mikutter
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' core devel plugin ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mikutter
	${INSTALL_SCRIPT} ${WRKDIR}/mikutter.sh ${DESTDIR}${PREFIX}/bin/mikutter
	${INSTALL_DATA} ${WRKDIR}/desktop ${DESTDIR}${PREFIX}/share/applications/mikutter.desktop

.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
