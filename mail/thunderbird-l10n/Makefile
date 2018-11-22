# $NetBSD: Makefile,v 1.68 2018/11/22 12:39:55 ryoon Exp $
#

TB_VER=		52.9.1
PKGNAME=	thunderbird-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

TB_LOCALES=	        ar ast be bg bn-BD br ca cs cy		\
                        da de dsb el en-GB en-US es-AR es-ES et	\
                        eu fi fr fy-NL ga-IE gd gl he hr hsb	\
                        hy-AM hu id is it ja ko			\
                        lt nb-NO nl nn-NO pl pa-IN		\
                        pt-BR pt-PT rm ro ru si sk		\
                        sl sq sr sv-SE ta-LK tr uk vi		\
                        zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../www/firefox52/xpi.mk"
.include "../../mk/bsd.pkg.mk"
