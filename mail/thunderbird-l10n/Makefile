# $NetBSD: Makefile,v 1.120 2024/06/07 23:54:34 ryoon Exp $
#

TB_VER=		115.11.1
PKGNAME=	thunderbird-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/linux-x86_64/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

DEPENDS+=	thunderbird>=${PKGVERSION_NOREV}:../../mail/thunderbird

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

INSTALLATION_DIRS=	lib/thunderbird/distribution/extensions

TB_LOCALES=		ar af ast be bg br ca cak cs cy		\
                        da de dsb el en-CA en-GB en-US es-AR es-ES et	\
                        eu fi fr fy-NL ga-IE gd gl he hr hsb	\
                        hu hy-AM id is it ja ka kab kk ko	\
                        lt nb-NO nl nn-NO pa-IN pl 		\
                        pt-BR pt-PT rm ro ru sk			\
                        sl sq sr sv-SE tr uk uz vi		\
                        zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird/distribution/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

do-install:
.for f in ${TB_LOCALES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f}.xpi \
	${DESTDIR}${EXTENSIONS_DIR}/langpack-${f}@thunderbird.mozilla.org.xpi
.endfor

.include "../../mk/bsd.pkg.mk"
