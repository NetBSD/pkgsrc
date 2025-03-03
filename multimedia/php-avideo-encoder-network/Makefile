# $NetBSD: Makefile,v 1.1 2025/03/03 15:29:15 manu Exp $

GITHUB_PROJECT=	AVideo-Encoder-Network
GITHUB_TAG=	3ac08dfa79fadbd83feb1f8dca3b9370452c8cf5
DISTNAME=	20240118
PKGNAME=	${PHP_PKG_PREFIX}-${GITHUB_PROJECT:tl}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=WWBN/}
HOMEPAGE=	https://github.com/WWBN/AVideo-Encoder-Network/
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Aggregator for AVideo Platform Encoder Servers
LICENSE=	gnu-gpl-v3

PHP_VERSIONS_ACCEPTED=	74 81 82 83

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli

.include "../../mk/bsd.prefs.mk"

PKG_USERS_VARS+=	APACHE_USER

AVIDEODIR=	share/avideo-encoder-network

MAKE_DIRS_PERMS+=	${AVIDEODIR} ${APACHE_USER} ${SHAREGRP} 0755
MAKE_DIRS_PERMS+=	${AVIDEODIR}/cache ${APACHE_USER} ${SHAREGRP} 0755

do-install:
	${FIND} ${WRKSRC} \( -type f -o -type d \) -exec ${CHMOD} og-w {} \;
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' \
	    \! -name .gitignore \! -name .gitmodules  -print | \
                ${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${AVIDEODIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
