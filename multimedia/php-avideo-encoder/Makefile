# $NetBSD: Makefile,v 1.1 2025/03/03 15:24:12 manu Exp $

GITHUB_PROJECT=	AVideo-Encoder
GITHUB_TAG=	refs/tags/${DISTNAME}
DISTNAME=	3.7
PKGNAME=	${PHP_PKG_PREFIX}-${GITHUB_PROJECT:tl}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=WWBN/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WWBN/AVideo-Encoder/
COMMENT=	Web-based video encoder for AVideo
LICENSE=	gnu-agpl-v3

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
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip

AVIDEODIR=	share/avideo-encoder

MAKE_DIRS_PERMS+=	${AVIDEODIR}/videos ${APACHE_USER} ${SHAREGRP} 0755

do-install:
	${FIND} ${WRKSRC} -type d \( -name .github -o -name .vscode \) \
	     -print | xargs ${RM} -rf
	${FIND} ${WRKSRC} \( -type f -o -type d \) -exec ${CHMOD} og-w {} \;
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' \
	    \! -name .gitignore -print | \
                ${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${AVIDEODIR}

.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
