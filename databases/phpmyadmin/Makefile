# $NetBSD: Makefile,v 1.102 2012/07/15 13:02:32 tron Exp $

DISTNAME=	phpMyAdmin-${DIST_VERSION}-all-languages
PKGNAME=	phpmyadmin-${DIST_VERSION:S/-//}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.xz

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://www.phpmyadmin.net/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=5.2.0:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=5.2.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-mysql{,i}>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.2.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.2.0:../../textproc/php-json

PKG_DESTDIR_SUPPORT=	user-destdir

FILES_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP:Q} PMCONFFILE=${PMCONFFILE:Q}
PLIST_SUBST+=	DIST_VERSION=${DIST_VERSION:Q}
MESSAGE_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP} PMCONFFILE=${PMCONFFILE:Q} \
		EXDIR=${EXDIR:Q}

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	3.5.2
DOC_FILES=	ChangeLog Documentation.txt LICENSE README \
		RELEASE-DATE-${DIST_VERSION}

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin

PKG_SYSCONFSUBDIR?=	phpmyadmin

NO_BUILD=		yes

INSTALLATION_DIRS+=	${PREFIX}/share/doc/phpmyadmin \
			${PREFIX}/share/examples/phpmyadmin \
			${PMDIR} ${PMDIR}/scripts

INSTALL_DIRS=	js
INSTALL_DIRS+=	js/canvg
INSTALL_DIRS+=	js/codemirror
INSTALL_DIRS+=	js/codemirror/lib
INSTALL_DIRS+=	js/codemirror/mode
INSTALL_DIRS+=	js/codemirror/mode/mysql
INSTALL_DIRS+=	js/highcharts
INSTALL_DIRS+=	js/jquery
INSTALL_DIRS+=	js/openlayers
INSTALL_DIRS+=	js/openlayers/img
INSTALL_DIRS+=	js/openlayers/theme
INSTALL_DIRS+=	js/openlayers/theme/default
INSTALL_DIRS+=	js/openlayers/theme/default/img
INSTALL_DIRS+=	js/pmd
INSTALL_DIRS+=	js/query
INSTALL_DIRS+=	js/rte
INSTALL_DIRS+=	libraries
INSTALL_DIRS+=	libraries/PHPExcel
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/CachedObjectStorage
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Calculation
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Cell
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Reader
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Reader/Excel2007
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Reader/Excel5
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/RichText
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher/DgContainer
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher/DgContainer/SpgrContainer
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher/DggContainer
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher/DggContainer/BstoreContainer
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/Escher/DggContainer/BstoreContainer/BSE
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/JAMA
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/JAMA/utils
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/OLE
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/OLE/PPS
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/PCLZip
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Shared/trend
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Style
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Worksheet
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Worksheet/Drawing
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Writer
INSTALL_DIRS+=	libraries/PHPExcel/PHPExcel/Writer/Excel2007
INSTALL_DIRS+=	libraries/auth
INSTALL_DIRS+=	libraries/auth/swekey
INSTALL_DIRS+=	libraries/bfShapeFiles
INSTALL_DIRS+=	libraries/chart
INSTALL_DIRS+=	libraries/chart/pChart
INSTALL_DIRS+=	libraries/chart/pChart/fonts
INSTALL_DIRS+=	libraries/config
INSTALL_DIRS+=	libraries/dbi
INSTALL_DIRS+=	libraries/engines
INSTALL_DIRS+=	libraries/export
INSTALL_DIRS+=	libraries/import
INSTALL_DIRS+=	libraries/import/upload
INSTALL_DIRS+=	libraries/php-gettext
INSTALL_DIRS+=	libraries/rte
INSTALL_DIRS+=	libraries/schema
INSTALL_DIRS+=	libraries/tcpdf
INSTALL_DIRS+=	libraries/tcpdf/cache
INSTALL_DIRS+=	libraries/tcpdf/config
INSTALL_DIRS+=	libraries/tcpdf/config/lang
INSTALL_DIRS+=	libraries/tcpdf/fonts
INSTALL_DIRS+=	libraries/tcpdf/fonts/dejavu-fonts-ttf-2.32
INSTALL_DIRS+=	libraries/tcpdf/fonts/dejavu-fonts-ttf-2.33
INSTALL_DIRS+=	libraries/transformations
INSTALL_DIRS+=	locale
INSTALL_DIRS+=	locale/ar
INSTALL_DIRS+=	locale/ar/LC_MESSAGES
INSTALL_DIRS+=	locale/be
INSTALL_DIRS+=	locale/be/LC_MESSAGES
INSTALL_DIRS+=	locale/be@latin
INSTALL_DIRS+=	locale/be@latin/LC_MESSAGES
INSTALL_DIRS+=	locale/bg
INSTALL_DIRS+=	locale/bg/LC_MESSAGES
INSTALL_DIRS+=	locale/bn
INSTALL_DIRS+=	locale/bn/LC_MESSAGES
INSTALL_DIRS+=	locale/ca
INSTALL_DIRS+=	locale/ca/LC_MESSAGES
INSTALL_DIRS+=	locale/cs
INSTALL_DIRS+=	locale/cs/LC_MESSAGES
INSTALL_DIRS+=	locale/da
INSTALL_DIRS+=	locale/da/LC_MESSAGES
INSTALL_DIRS+=	locale/de
INSTALL_DIRS+=	locale/de/LC_MESSAGES
INSTALL_DIRS+=	locale/el
INSTALL_DIRS+=	locale/el/LC_MESSAGES
INSTALL_DIRS+=	locale/en_GB
INSTALL_DIRS+=	locale/en_GB/LC_MESSAGES
INSTALL_DIRS+=	locale/es
INSTALL_DIRS+=	locale/es/LC_MESSAGES
INSTALL_DIRS+=	locale/et
INSTALL_DIRS+=	locale/et/LC_MESSAGES
INSTALL_DIRS+=	locale/fi
INSTALL_DIRS+=	locale/fi/LC_MESSAGES
INSTALL_DIRS+=	locale/fr
INSTALL_DIRS+=	locale/fr/LC_MESSAGES
INSTALL_DIRS+=	locale/gl
INSTALL_DIRS+=	locale/gl/LC_MESSAGES
INSTALL_DIRS+=	locale/hi
INSTALL_DIRS+=	locale/hi/LC_MESSAGES
INSTALL_DIRS+=	locale/hr
INSTALL_DIRS+=	locale/hr/LC_MESSAGES
INSTALL_DIRS+=	locale/hu
INSTALL_DIRS+=	locale/hu/LC_MESSAGES
INSTALL_DIRS+=	locale/id
INSTALL_DIRS+=	locale/id/LC_MESSAGES
INSTALL_DIRS+=	locale/it
INSTALL_DIRS+=	locale/it/LC_MESSAGES
INSTALL_DIRS+=	locale/ja
INSTALL_DIRS+=	locale/ja/LC_MESSAGES
INSTALL_DIRS+=	locale/ka
INSTALL_DIRS+=	locale/ka/LC_MESSAGES
INSTALL_DIRS+=	locale/lt
INSTALL_DIRS+=	locale/lt/LC_MESSAGES
INSTALL_DIRS+=	locale/mn
INSTALL_DIRS+=	locale/mn/LC_MESSAGES
INSTALL_DIRS+=	locale/nb
INSTALL_DIRS+=	locale/nb/LC_MESSAGES
INSTALL_DIRS+=	locale/nl
INSTALL_DIRS+=	locale/nl/LC_MESSAGES
INSTALL_DIRS+=	locale/pl
INSTALL_DIRS+=	locale/pl/LC_MESSAGES
INSTALL_DIRS+=	locale/pt_BR
INSTALL_DIRS+=	locale/pt_BR/LC_MESSAGES
INSTALL_DIRS+=	locale/ro
INSTALL_DIRS+=	locale/ro/LC_MESSAGES
INSTALL_DIRS+=	locale/ru
INSTALL_DIRS+=	locale/ru/LC_MESSAGES
INSTALL_DIRS+=	locale/si
INSTALL_DIRS+=	locale/si/LC_MESSAGES
INSTALL_DIRS+=	locale/sk
INSTALL_DIRS+=	locale/sk/LC_MESSAGES
INSTALL_DIRS+=	locale/sl
INSTALL_DIRS+=	locale/sl/LC_MESSAGES
INSTALL_DIRS+=	locale/sr
INSTALL_DIRS+=	locale/sr/LC_MESSAGES
INSTALL_DIRS+=	locale/sr@latin
INSTALL_DIRS+=	locale/sr@latin/LC_MESSAGES
INSTALL_DIRS+=	locale/sv
INSTALL_DIRS+=	locale/sv/LC_MESSAGES
INSTALL_DIRS+=	locale/tr
INSTALL_DIRS+=	locale/tr/LC_MESSAGES
INSTALL_DIRS+=	locale/uk
INSTALL_DIRS+=	locale/uk/LC_MESSAGES
INSTALL_DIRS+=	locale/uz
INSTALL_DIRS+=	locale/uz/LC_MESSAGES
INSTALL_DIRS+=	locale/uz@latin
INSTALL_DIRS+=	locale/uz@latin/LC_MESSAGES
INSTALL_DIRS+=	locale/zh_CN
INSTALL_DIRS+=	locale/zh_CN/LC_MESSAGES
INSTALL_DIRS+=	locale/zh_TW
INSTALL_DIRS+=	locale/zh_TW/LC_MESSAGES
INSTALL_DIRS+=	scripts
INSTALL_DIRS+=	setup/frames
INSTALL_DIRS+=	setup/lib
INSTALL_DIRS+=	themes
INSTALL_DIRS+=	themes/original
INSTALL_DIRS+=	themes/original/css
INSTALL_DIRS+=	themes/original/img
INSTALL_DIRS+=	themes/original/img/pmd
INSTALL_DIRS+=	themes/original/jquery
INSTALL_DIRS+=	themes/original/jquery/images
INSTALL_DIRS+=	themes/pmahomme
INSTALL_DIRS+=	themes/pmahomme/css
INSTALL_DIRS+=	themes/pmahomme/img
INSTALL_DIRS+=	themes/pmahomme/img/pmd
INSTALL_DIRS+=	themes/pmahomme/jquery
INSTALL_DIRS+=	themes/pmahomme/jquery/images

.for dir in $(INSTALL_DIRS)
INSTALLATION_DIRS+=	${PMDIR}/${dir}
.endfor

do-configure:
	${SED} -e "s|@PMDIR@|${PMDIR}|g" ${FILESDIR}/phpmyadmin.conf	\
		>${WRKDIR}/phpmyadmin.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.css ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ico ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PMDIR}

	${MV} ${DESTDIR}${PREFIX}/share/phpmyadmin/config.sample.inc.php \
	  ${DESTDIR}${EXDIR}/config.inc.php

	${INSTALL_DATA} ${WRKSRC}/Documentation.html ${DESTDIR}${PMDIR}

	for dir in ${INSTALL_DIRS}; do					\
		for file in ${WRKSRC}/$$dir/*; do			\
			case "$$file" in				\
			*.orig|*.sh)					\
				;;					\
			*)						\
				if [ -f "$$file" ]; then		\
					${INSTALL_DATA} "$$file"	\
					  ${DESTDIR}${PMDIR}/$$dir;	\
				fi					\
				;;					\
			esac;						\
		done							\
	done

	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOC_FILES} ${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${DESTDIR}${EXDIR}/apache.conf

	${RM} -f ${DESTDIR}${PREFIX}/share/phpmyadmin/libraries/footer.inc.php.orig

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
