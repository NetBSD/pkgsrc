# $NetBSD: Makefile,v 1.6 2012/09/18 16:47:53 ryoon Exp $
#

TB_VER=		10.0.7
PKGNAME=	thunderbird10-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA_ESR:=thunderbird/releases/${TB_VER}esr/linux-i686/xpi/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

TB_LOCALES=	        ar ast be bg bn-BD br ca cs		\
                        da de el en-GB en-US es-AR es-ES et	\
                        eu fi fr fy-NL ga-IE gd gl he		\
                        hu id is it ja ko			\
                        lt nb-NO nl nn-NO			\
                        pa-IN pl pt-BR pt-PT rm ro ru si sk	\
                        sl sq sr sv-SE ta-LK tr uk vi		\
                        zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird10/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../devel/xulrunner10/xpi.mk"
.include "../../mk/bsd.pkg.mk"
