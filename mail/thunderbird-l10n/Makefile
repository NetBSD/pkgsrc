# $NetBSD: Makefile,v 1.41 2016/02/09 21:22:13 ryoon Exp $
#

TB_VER=		38.5.1
PKGNAME=	thunderbird-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

TB_LOCALES=	        ar be bn-BD br ca cs			\
                        da de el en-GB en-US es-AR es-ES et	\
                        eu fi fr fy-NL ga-IE he			\
                        hu id is it ja ko			\
                        lt nb-NO nl nn-NO			\
                        pt-BR pt-PT rm ru si sk			\
                        sl sq sv-SE ta-LK tr uk vi		\
                        zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../www/firefox38/xpi.mk"
.include "../../mk/bsd.pkg.mk"
