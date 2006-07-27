# $NetBSD: Makefile,v 1.17 2006/07/27 00:09:06 hubertf Exp $
#

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=		ttf2pk-${FT_VERS}
CATEGORIES=		print

MAINTAINER=		bernhard@SDG.de,pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		TrueType to TeX PK font converter

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-kpathsea-include=${BUILDLINK_PREFIX.teTeX-bin}/include
CONFIGURE_ARGS+=	--with-kpathsea-lib=${BUILDLINK_PREFIX.teTeX-bin}/lib

T2PSRC=			${WRKSRC}/contrib/ttf2pk
CONFIGURE_DIRS+=	${T2PSRC}
BUILD_DIRS=		${T2PSRC}

BUILD_TARGET=		depend all

USE_DIRS+=		texmf-1.0
USE_LIBTOOL=		yes

INSTALLATION_DIRS=	bin man/man1

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_PROGRAM}	${T2PSRC}/ttf2pk \
				${T2PSRC}/ttf2tfm \
				${PREFIX}/bin
	${INSTALL_DATA}		${T2PSRC}/ttf2pk.1 \
				${T2PSRC}/ttf2tfm.1 \
				${PREFIX}/man/man1
	${INSTALL_DATA_DIR}	${PKG_LOCALTEXMFPREFIX}/doc/ttf2pk
	${INSTALL_DATA}		${T2PSRC}/BUGS \
				${T2PSRC}/README \
				${T2PSRC}/TODO \
				${T2PSRC}/ttf2pk.doc \
				${T2PSRC}/data/ttfonts.map \
				${PKG_LOCALTEXMFPREFIX}/doc/ttf2pk
	${INSTALL_DATA_DIR}	${PKG_LOCALTEXMFPREFIX}/ttf2tfm
	${LN} -fs		ttf2tfm \
				${PKG_LOCALTEXMFPREFIX}/ttf2pk
	${INSTALL_DATA_DIR}	${PKG_LOCALTEXMFPREFIX}/ttf2tfm/base
	${INSTALL_DATA}		${T2PSRC}/data/*.enc \
				${T2PSRC}/data/*.rpl \
				${T2PSRC}/data/*.sfd \
				${PKG_LOCALTEXMFPREFIX}/ttf2tfm/base
	${TOUCH}		${PKG_LOCALTEXMFPREFIX}/ttf2tfm/base/ttfonts.map

.include "../../mk/bsd.pkg.mk"
