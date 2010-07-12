# $NetBSD: Makefile,v 1.2 2010/07/12 17:10:37 tnn Exp $
#

TB_VER=		3.1
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
                        eu fi fr fy-NL ga-IE he			\
                        hu id is it ja ko			\
                        lt nb-NO nl nn-NO			\
                        pa-IN pl pt-BR pt-PT ro ru sk		\
                        sl sq sv-SE tr uk			\
                        zh-CN zh-TW
# broken: si

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../devel/xulrunner/xpi.mk"
.include "../../mk/bsd.pkg.mk"
