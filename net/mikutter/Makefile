# $NetBSD: Makefile,v 1.52.2.1 2012/12/15 17:53:51 tron Exp $
#

DISTNAME=	mikutter.0.1.1.1063
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	http://mikutter.hachune.net/bin/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mikutter.hachune.net/
COMMENT=	Simply, powerfully, and moefully twitter client
LICENSE=	gnu-gpl-v3

RUBY_VERSION_SUPPORTED=	193

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${RUBY_PKGPREFIX}-hmac>=0.4.0:../../security/ruby-hmac
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=1.0.0:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.6:../../security/ruby-oauth
# need included escape.rb
#DEPENDS+=	${RUBY_PKGPREFIX}-escape-[0-9]*:../../textproc/ruby-escape
DEPENDS+=	${RUBY_PKGPREFIX}-memoize>=1.3.1:../../devel/ruby-memoize
DEPENDS+=	${RUBY_PKGPREFIX}-bsearch>=1.5:../../devel/ruby-bsearch
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient-[0-9]*:../../www/ruby-httpclient
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.2.6nb1:../../net/ruby-addressable
# notify-send
DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify

RUBY_JSON_REQD=	1.5.1
WRKSRC=		${WRKDIR}/mikutter
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

REPLACE_RUBY=	mikutter.rb
REPLACE_RUBY_DIRS=	core
.include "../../lang/ruby/replace.mk"

INSTALLATION_DIRS+=	bin share/doc/mikutter share/applications share/mikutter

do-build:
	cd ${WRKSRC}/core/lib && \
		${RM} -rf json* hmac*.rb memoize.rb oauth* ruby-bsearch-* addressable && \
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/desktop.in > ${WRKDIR}/desktop
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/mikutter.sh.in > ${WRKDIR}/mikutter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mikutter.rb ${DESTDIR}${PREFIX}/share/mikutter
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' core plugin ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mikutter
	${INSTALL_SCRIPT} ${WRKDIR}/mikutter.sh ${DESTDIR}${PREFIX}/bin/mikutter
	${INSTALL_DATA} ${WRKDIR}/desktop ${DESTDIR}${PREFIX}/share/applications/mikutter.desktop

.include "../../lang/ruby/json.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
