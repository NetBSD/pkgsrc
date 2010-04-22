# $NetBSD: Makefile,v 1.1.1.1 2010/04/22 16:59:05 tnn Exp $
#

TB_VER=		3.0.4
PKGNAME=	thunderbird-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/linux-i686/xpi/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

TB_LOCALES=	        af ar be bg bn-BD ca cs			\
                        da de el en-GB es-AR es-ES et		\
                        eu fi fr fy-NL ga-IE gl he		\
                        hu id is it ja ka ko			\
                        lt nb-NO nl nn-NO			\
                        pa-IN pl pt-BR pt-PT ro ru sk		\
                        sq sr sv-SE tr uk			\
                        vi zh-CN zh-TW
# broken: ta-LK, si

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../devel/xulrunner/xpi.mk"
.include "../../mk/bsd.pkg.mk"
