# $NetBSD: Makefile,v 1.96 2015/01/12 12:03:47 obache Exp $
#

DISTNAME=	mikutter.3.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	http://mikutter.hachune.net/bin/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mikutter.hachune.net/
COMMENT=	Simple, powerful, and moeful twitter client
LICENSE=	mit AND cc-by-sa-v3.0

RUBY_VERSION_SUPPORTED=	200 21

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=2.2.3:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.0.1:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-memoize>=1.3:../../devel/ruby-memoize
DEPENDS+=	${RUBY_PKGPREFIX}-hmac>=0.4:../../security/ruby-hmac
DEPENDS+=	${RUBY_PKGPREFIX}-typed-array>=0.1:../../misc/ruby-typed-array
DEPENDS+=	${RUBY_PKGPREFIX}-delayer-[0-9]*:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient-[0-9]*:../../www/ruby-httpclient
DEPENDS+=	${RUBY_PKGPREFIX}-moneta>=0.7:../../databases/ruby-moneta

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
	${INSTALL_DATA} ${WRKSRC}/Gemfile ${DESTDIR}${PREFIX}/share/mikutter
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' core devel plugin ${DESTDIR}${PREFIX}/share/mikutter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mikutter
	${INSTALL_SCRIPT} ${WRKDIR}/mikutter.sh ${DESTDIR}${PREFIX}/bin/mikutter
	${INSTALL_DATA} ${WRKDIR}/desktop ${DESTDIR}${PREFIX}/share/applications/mikutter.desktop

RUBY_JSON_TYPE=	pure
RUBY_JSON_REQD=	1.8
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
