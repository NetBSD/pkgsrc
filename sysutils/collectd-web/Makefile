# $NetBSD: Makefile,v 1.10 2025/12/06 22:24:28 wiz Exp $

DISTNAME=	collectd-web-0.11.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=httpdss/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/httpdss/collectd-web
COMMENT=	Web interface for Collectd
LICENSE=	gnu-gpl-v2

# needs RRDs perl module
DEPENDS+=	rrdtool>=0:../../databases/rrdtool
# needs data in RRD format
DEPENDS+=	collectd-rrdtool>=0:../../sysutils/collectd-rrdtool
DEPENDS+=	p5-JSON>=2.94:../../converters/p5-JSON
DEPENDS+=	p5-CGI>=4.36:../../www/p5-CGI
DEPENDS+=	${PYPKGPREFIX}-dotenv-[0-9]*:../../devel/py-dotenv
# only needed in some instances, not when using the Python server
#DEPENDS+=	fcgiwrap>=1.1.0:../../www/fcgiwrap
#DEPENDS+=	spawn-fcgi>=1.6.3:../../www/spawn-fcgi

NO_BUILD=		yes
USE_TOOLS+=		pax perl:run
REPLACE_PERL+=		cgi-bin/*.pl
REPLACE_PERL+=		cgi-bin/*.cgi
REPLACE_SH+=		check_deps.sh
REPLACE_SH+=		debian/prerm
REPLACE_PYTHON+=	runserver.py

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e "s,/etc/collectd/collection.conf,${PKG_SYSCONFDIR}/collectd-web.conf,"
SUBST_FILES.config+=	cgi-bin/collection.modified.cgi
SUBST_MESSAGE.config=	Using config file ${PREFIX}/etc/collectd-web.conf
SUBST_STAGE.config=	pre-configure

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	bin share/examples/collectd-web
CONF_FILES+=		share/examples/collectd-web/collectd-web.conf \
			${PKG_SYSCONFDIR}/collectd-web.conf

# configure target is needed, otherwise REPLACE_* do not happen
# use it for generating a script
do-configure:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/collectd-web.sh
	${ECHO} "cd ${PREFIX}/share/collectd-web" >> ${WRKDIR}/collectd-web.sh
	${ECHO} "${PYTHONBIN} runserver.py \"\$$@\"" >> ${WRKDIR}/collectd-web.sh

do-install:
	cd ${WRKSRC} && pax -rw -pp [A-Za-z]* ${DESTDIR}${PREFIX}/share/collectd-web
	${RM} ${DESTDIR}${PREFIX}/share/collectd-web/cgi-bin/collection.modified.cgi.orig
	${INSTALL_SCRIPT} ${WRKDIR}/collectd-web.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/collectd-web.conf ${DESTDIR}${PREFIX}/share/examples/collectd-web

.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
