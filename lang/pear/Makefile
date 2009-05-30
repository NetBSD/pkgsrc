# $NetBSD: Makefile,v 1.9 2009/05/30 22:59:52 abs Exp $
#

DISTNAME=	PEAR-1.5.4
PKGREVISION=	3
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/PEAR/pear/}
CATEGORIES=	lang
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/
COMMENT=	PEAR Base System for PHP

USE_LANGUAGES=	# none
EXTRACT_ONLY=	# none
USE_TOOLS+=	gzcat

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == "4"
CONFLICTS+=	php<4.4.6nb1
.elif ${PKG_PHP_VERSION} == "5"
CONFLICTS+=	php<5.2.1nb2
.endif

CONF_FILES=	${PREFIX}/share/examples/pear/pear.conf \
		${PKG_SYSCONFDIR}/pear.conf

BUNDLE=		${WRKSRC}/install/go-pear-bundle

# everything else that forms a part of the "base" PEAR install
#
PEAR_SRCS=		PEAR-1.5.4${EXTRACT_SUFX}
DISTFILES+=		${PEAR_SRCS}
EXTRACT_ONLY+=		${PEAR_SRCS}

ARCHIVE_SRCS=		Archive_Tar-1.3.2${EXTRACT_SUFX}
ARCHIVE_WRKSRC=		${WRKDIR}/${ARCHIVE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${ARCHIVE_SRCS}
EXTRACT_ONLY+=		${ARCHIVE_SRCS}

CONSOLE_SRCS=		Console_Getopt-1.2.2${EXTRACT_SUFX}
CONSOLE_WRKSRC=		${WRKDIR}/${CONSOLE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${CONSOLE_SRCS}
EXTRACT_ONLY+=		${CONSOLE_SRCS}

STRUCTURES_SRCS=	Structures_Graph-1.0.2${EXTRACT_SUFX}
DISTFILES+=		${STRUCTURES_SRCS}
#
# end of base components

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	install/go-pear.php
SUBST_SED.config=	-e "s|@WRKSRC@|${WRKSRC}|g"
SUBST_SED.config+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

SUBST_CLASSES+=		pear
SUBST_STAGE.pear=	post-patch
SUBST_FILES.pear=	pear.sh
SUBST_SED.pear=		-e "s|@php_bin@|${PREFIX}/bin/php|g"
SUBST_SED.pear+=	-e "s|@php_dir@|${PREFIX}/lib/php|g"
SUBST_SED.pear+=	-e "s|@SH@|${SH}|g"
SUBST_MESSAGE.pear=	Fixing pear installation script.

post-extract:
	${RM} ${WRKSRC}/INSTALL
	${MKDIR} ${WRKSRC}/install
	${MKDIR} ${BUNDLE}
	${CP} ${FILESDIR}/go-pear.php ${WRKSRC}/install
	${CP} ${FILESDIR}/pear.sh ${WRKSRC}

do-build:
	${GZCAT} ${DISTDIR}/${ARCHIVE_SRCS} > \
		${BUNDLE}/${ARCHIVE_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${CONSOLE_SRCS} > \
		${BUNDLE}/${CONSOLE_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${PEAR_SRCS} > \
		${BUNDLE}/${PEAR_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${STRUCTURES_SRCS} > \
		${BUNDLE}/${STRUCTURES_SRCS:S/${EXTRACT_SUFX}/.tar/}

	${CP} ${ARCHIVE_WRKSRC}/Archive/Tar.php ${BUNDLE}
	${CP} ${CONSOLE_WRKSRC}/Console/Getopt.php ${BUNDLE}
	${CP} ${WRKSRC}/PEAR.php ${BUNDLE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/pear
	${PREFIX}/bin/php ${DESTDIR}${WRKSRC}/install/go-pear.php local
	${INSTALL_SCRIPT} ${WRKSRC}/pear.sh ${DESTDIR}${PREFIX}/bin/pear
	${INSTALL_DATA} ${WRKSRC}/pear.conf \
		${DESTDIR}${PREFIX}/share/examples/pear/pear.conf

.include "${PHPPKGSRCDIR}/buildlink3.mk"

.if ${PKG_PHP_VERSION} == "4"
BUILDLINK_API_DEPENDS.php+=	php>=4.4.6nb1
.elif ${PKG_PHP_VERSION} == "5"
BUILDLINK_API_DEPENDS.php+=	php>=5.2.1nb2
.endif

.include "../../mk/bsd.pkg.mk"
