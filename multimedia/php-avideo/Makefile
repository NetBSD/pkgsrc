# $NetBSD: Makefile,v 1.1 2025/03/03 15:21:04 manu Exp $

GITHUB_PROJECT=	AVideo
GITHUB_TAG=	refs/tags/${DISTNAME}
DISTNAME=	14.3
PKGNAME=	${PHP_PKG_PREFIX}-${GITHUB_PROJECT:tl}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=WWBN/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WWBN/AVideo/
COMMENT=	Web-based video streaming platform
LICENSE=	json-license

PHP_VERSIONS_ACCEPTED=	74 81 82 83

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_TOOLS=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

DEPENDS+=	wget>=1.24.5:../../net/wget
DEPENDS+=	unzip>=6.0:../../archivers/unzip
DEPENDS+=	lsof>=4.91:../../sysutils/lsof

.include "../../mk/bsd.prefs.mk"

PKG_USERS_VARS+=	APACHE_USER

AVIDEODIR=	share/avideo

MAKE_DIRS_PERMS+=	${AVIDEODIR}/videos ${APACHE_USER} ${SHAREGRP} 0755

do-install:
	${FIND} ${WRKSRC} -type d \( -name .github -o -name .vscode \) \
	     -print | xargs ${RM} -rf
	${FIND} ${WRKSRC} \( -type f -o -type d \) -exec ${CHMOD} og-w {} \;
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' \
	    \! -name .editorconfig \! -name .gitconfig \
	    \! -name .gitattributes \
	    \! -name .gitignore \! -name .gitmodules  -print | \
                ${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${AVIDEODIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
