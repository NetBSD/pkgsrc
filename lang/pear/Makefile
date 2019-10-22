# $NetBSD: Makefile,v 1.50 2019/10/22 07:46:25 taca Exp $
#

DISTNAME=	PEAR-1.10.9
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/PEAR/pear/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	pear20151210

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/
COMMENT=	PEAR Base System for PHP
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none
EXTRACT_ONLY=	# none
USE_TOOLS+=	gzcat

.include "../../lang/php/phpversion.mk"

CONFLICTS+=	php<5.2.1nb2

PKG_SYSCONFVAR=	php
CONF_FILES=	${PREFIX}/share/examples/pear/pear.conf \
		${PKG_SYSCONFDIR}/pear.conf

BUNDLE=		${WRKSRC}/install/go-pear-bundle

# everything else that forms a part of the "base" PEAR install
#
PEAR_SRCS=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${PEAR_SRCS}
EXTRACT_ONLY+=		${PEAR_SRCS}

ARCHIVE_SRCS=		Archive_Tar-1.4.8${EXTRACT_SUFX}
ARCHIVE_WRKSRC=		${WRKDIR}/${ARCHIVE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${ARCHIVE_SRCS}
EXTRACT_ONLY+=		${ARCHIVE_SRCS}

CONSOLE_SRCS=		Console_Getopt-1.4.2${EXTRACT_SUFX}
CONSOLE_WRKSRC=		${WRKDIR}/${CONSOLE_SRCS:S/${EXTRACT_SUFX}//}
DISTFILES+=		${CONSOLE_SRCS}
EXTRACT_ONLY+=		${CONSOLE_SRCS}

STRUCTURES_SRCS=	Structures_Graph-1.1.1${EXTRACT_SUFX}
DISTFILES+=		${STRUCTURES_SRCS}

XMLUTIL_SRCS=		XML_Util-1.4.3${EXTRACT_SUFX}
DISTFILES+=		${XMLUTIL_SRCS}

#
# end of base components

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	install/go-pear.php
SUBST_VARS.config=	WRKSRC
SUBST_VARS.config+=	PREFIX
SUBST_MESSAGE.config=	Fixing configuration files.

REPLACE_SH+=		script/pear.sh

INSTALLATION_DIRS+=	share/examples/pear

pre-patch:
	${RM} ${WRKSRC}/INSTALL
	${MKDIR} ${WRKSRC}/install
	${MKDIR} ${BUNDLE}
	${CP} ${FILESDIR}/go-pear.php ${WRKSRC}/install
	${CP} ${WRKSRC}/PEAR.php ${BUNDLE}

do-build:
.for f in ${DISTFILES}
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${f} > \
		${BUNDLE}/${f:S/${EXTRACT_SUFX}/.tar/}
.endfor
	${CP} ${ARCHIVE_WRKSRC}/Archive/Tar.php ${BUNDLE}
	${CP} ${CONSOLE_WRKSRC}/Console/Getopt.php ${BUNDLE}

do-install:
	${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/php ${WRKSRC}/install/go-pear.php local
	${INSTALL_DATA} ${WRKSRC}/pear.conf \
		${DESTDIR}${PREFIX}/share/examples/pear/pear.conf

.include "${PHPPKGSRCDIR}/buildlink3.mk"

BUILDLINK_API_DEPENDS.php+=	php>=5.2.1nb2

.include "../../mk/bsd.pkg.mk"
