# $NetBSD: Makefile,v 1.4 2010/03/16 16:02:20 taca Exp $
#

DISTNAME=	ampache-3.5.3
CATEGORIES=	audio
MASTER_SITES=	http://ampache.org/downloads/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://ampache.org/
COMMENT=	Web-based Audio file manager

DEPENDS+=       ${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=       ${PHP_PKG_PREFIX}-gettext>=0:../../devel/php-gettext
DEPENDS+=       ${PHP_PKG_PREFIX}-iconv>=0:../../converters/php-iconv
DEPENDS+=       ${PHP_PKG_PREFIX}-mbstring>=0:../../converters/php-mbstring
DEPENDS+=       ${PHP_PKG_PREFIX}-mysql>=0:../../databases/php-mysql

NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pax
LICENSE=       		gnu-gpl-v2

INSTDIR=		${PREFIX}/share/ampache
EGDIR=			${PREFIX}/share/examples

MESSAGE_SUBST+=		INSTDIR=${INSTDIR:Q}
FILES_SUBST+=		INSTDIR=${INSTDIR:Q}

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	ampache.conf
SUBST_SED.files=	-e "s|@INSTDIR@|${INSTDIR}|g"
SUBST_MESSAGE.files=	Substituting paths into apache config fragment

CONF_FILES=		${EGDIR}/ampache.conf \
			${PKG_SYSCONFDIR}/ampache.conf

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EGDIR}

post-extract:
	${CP} ${FILESDIR}/ampache.conf ${WRKSRC}/ampache.conf

do-install:
	${CHMOD} -x ${WRKSRC}/docs/[A-Z]*
	${INSTALL_DATA} ${WRKSRC}/ampache.conf ${DESTDIR}${EGDIR}/ampache.conf
	set -e; cd ${WRKSRC} && pax -rw -pe . ${DESTDIR}${INSTDIR}
	${RM} -f ${DESTDIR}${INSTDIR}/ampache.conf
	${FIND} ${DESTDIR}${INSTDIR} -name '*.orig' | ${XARGS} ${RM}

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
