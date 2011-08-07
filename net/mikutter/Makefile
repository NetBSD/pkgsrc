# $NetBSD: Makefile,v 1.16 2011/08/07 14:53:12 obache Exp $
#

DISTNAME=	mikutter.0.0.3.456
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	http://mikutter.hachune.net/bin/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mikutter.hachune.net/
COMMENT=	Moest Twitter Client
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.5.1:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-hmac>=0.4.0:../../security/ruby-hmac
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk-[0-9]*:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth
# need included escape.rb
#DEPENDS+=	${RUBY_PKGPREFIX}-escape-[0-9]*:../../textproc/ruby-escape
DEPENDS+=	${RUBY_PKGPREFIX}-memoize>=1.3.1:../../devel/ruby-memoize
DEPENDS+=	${RUBY_PKGPREFIX}-bsearch>=1.5:../../devel/ruby-bsearch
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient-[0-9]*:../../www/ruby-httpclient
# notif-send
DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify

WRKSRC=		${WRKDIR}/mikutter
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

REPLACE_RUBY=	mikutter.rb
REPLACE_RUBY_DIRS=	core
.include "../../lang/ruby/replace.mk"

INSTALLATION_DIRS+=	bin share/doc/mikutter share/applications share/mikutter

do-build:
	cd ${WRKSRC}/core/lib && \
		${RM} -rf json* hmac*.rb oauth* memoize.rb ruby-bsearch-* && \
		${MKDIR} miku && ${MV} escape.rb miku/escape.rb
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/desktop.in > ${WRKDIR}/desktop
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/mikutter.sh.in > ${WRKDIR}/mikutter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mikutter.rb ${DESTDIR}${PREFIX}/share/mikutter
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' core plugin ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mikutter
	${INSTALL_SCRIPT} ${WRKDIR}/mikutter.sh ${DESTDIR}${PREFIX}/bin/mikutter
	${INSTALL_DATA} ${WRKDIR}/desktop ${DESTDIR}${PREFIX}/share/applications/mikutter.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
