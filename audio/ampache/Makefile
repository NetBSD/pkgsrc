# $NetBSD: Makefile,v 1.17 2023/12/21 13:07:17 zafer Exp $
#

DISTNAME=	ampache-3.5.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ampache/}
GITHUB_PROJECT=	ampache
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://ampache.org/
COMMENT=	Web-based Audio file manager

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=0:../../databases/php-mysql

PHP_VERSIONS_ACCEPTED=	56
NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pax
LICENSE=		gnu-gpl-v2

INSTDIR=		${PREFIX}/share/ampache
EGDIR=			${PREFIX}/share/examples

MESSAGE_SUBST+=		INSTDIR=${INSTDIR:Q}
FILES_SUBST+=		INSTDIR=${INSTDIR:Q}

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	ampache.conf
SUBST_VARS.files=	INSTDIR
SUBST_MESSAGE.files=	Substituting paths into apache config fragment

CONF_FILES=		${EGDIR}/ampache.conf \
			${PKG_SYSCONFDIR}/ampache.conf

INSTALLATION_DIRS+=	${EGDIR} ${INSTDIR}

REPLACE_SH=		locale/base/gather-messages.sh

post-extract:
	${CP} ${FILESDIR}/ampache.conf ${WRKSRC}/ampache.conf

do-install:
	${CHMOD} -x ${WRKSRC}/docs/[A-Z]*
	${INSTALL_DATA} ${WRKSRC}/ampache.conf ${DESTDIR}${EGDIR}/ampache.conf
	set -e; cd ${WRKSRC} && pax -rw -pp . ${DESTDIR}${INSTDIR}
	${RM} -f ${DESTDIR}${INSTDIR}/ampache.conf
	${FIND} ${DESTDIR}${INSTDIR} -name '*.orig' | ${XARGS} ${RM} -f

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
