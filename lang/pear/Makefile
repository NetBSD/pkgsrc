# $NetBSD: Makefile,v 1.23 2012/10/02 20:11:48 asau Exp $
#

DISTNAME=	PEAR-1.9.4
PKGREVISION=	3
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/PEAR/pear/}
CATEGORIES=	lang
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/
COMMENT=	PEAR Base System for PHP
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none
EXTRACT_ONLY=	# none
USE_TOOLS+=	gzcat

.include "../../lang/php/phpversion.mk"

CONFLICTS+=	php<5.2.1nb2

CONF_FILES=	${PREFIX}/share/examples/pear/pear.conf \
		${PKG_SYSCONFDIR}/pear.conf

BUNDLE=		${WRKSRC}/install/go-pear-bundle

# everything else that forms a part of the "base" PEAR install
#
PEAR_SRCS=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${PEAR_SRCS}
EXTRACT_ONLY+=		${PEAR_SRCS}

ARCHIVE_SRCS=		Archive_Tar-1.3.10${EXTRACT_SUFX}
ARCHIVE_WRKSRC=		${WRKDIR}/${ARCHIVE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${ARCHIVE_SRCS}
EXTRACT_ONLY+=		${ARCHIVE_SRCS}

CONSOLE_SRCS=		Console_Getopt-1.3.1${EXTRACT_SUFX}
CONSOLE_WRKSRC=		${WRKDIR}/${CONSOLE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${CONSOLE_SRCS}
EXTRACT_ONLY+=		${CONSOLE_SRCS}

STRUCTURES_SRCS=	Structures_Graph-1.0.4${EXTRACT_SUFX}
DISTFILES+=		${STRUCTURES_SRCS}

XMLUTIL_SRCS=		XML_Util-1.2.1${EXTRACT_SUFX}
DISTFILES+=		${XMLUTIL_SRCS}

#
# end of base components

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	install/go-pear.php
SUBST_SED.config=	-e "s|@WRKSRC@|${WRKSRC}|g"
SUBST_SED.config+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

REPLACE_SH+=		script/pear.sh

INSTALLATION_DIRS+=	share/examples/pear

post-extract:
	${RM} ${WRKSRC}/INSTALL
	${MKDIR} ${WRKSRC}/install
	${MKDIR} ${BUNDLE}
	${CP} ${FILESDIR}/go-pear.php ${WRKSRC}/install
	${CP} ${FILESDIR}/PEAR.php ${BUNDLE}

do-build:
	${GZCAT} ${DISTDIR}/${ARCHIVE_SRCS} > \
		${BUNDLE}/${ARCHIVE_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${CONSOLE_SRCS} > \
		${BUNDLE}/${CONSOLE_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${PEAR_SRCS} > \
		${BUNDLE}/${PEAR_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${STRUCTURES_SRCS} > \
		${BUNDLE}/${STRUCTURES_SRCS:S/${EXTRACT_SUFX}/.tar/}
	${GZCAT} ${DISTDIR}/${XMLUTIL_SRCS} > \
		${BUNDLE}/${XMLUTIL_SRCS:S/${EXTRACT_SUFX}/.tar/}

	${CP} ${ARCHIVE_WRKSRC}/Archive/Tar.php ${BUNDLE}
	${CP} ${CONSOLE_WRKSRC}/Console/Getopt.php ${BUNDLE}

do-install:
	${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/php ${WRKSRC}/install/go-pear.php local
	${INSTALL_DATA} ${WRKSRC}/pear.conf \
		${DESTDIR}${PREFIX}/share/examples/pear/pear.conf

.include "${PHPPKGSRCDIR}/buildlink3.mk"

BUILDLINK_API_DEPENDS.php+=	php>=5.2.1nb2

.include "../../mk/bsd.pkg.mk"
