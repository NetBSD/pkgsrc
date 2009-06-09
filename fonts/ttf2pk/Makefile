# $NetBSD: Makefile,v 1.22 2009/06/09 21:31:04 minskim Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=		ttf2pk-${FT_VERS}
PKGREVISION=		2
CATEGORIES=		print

MAINTAINER=		bernhard@SDG.de
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

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_PROGRAM}	${T2PSRC}/ttf2pk \
				${T2PSRC}/ttf2tfm \
				${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}		${T2PSRC}/ttf2pk.1 \
				${T2PSRC}/ttf2tfm.1 \
				${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR}	${DESTDIR}${PREFIX}/share/texmf-dist/doc/ttf2pk
	${INSTALL_DATA}		${T2PSRC}/BUGS \
				${T2PSRC}/README \
				${T2PSRC}/TODO \
				${T2PSRC}/ttf2pk.doc \
				${T2PSRC}/data/ttfonts.map \
				${DESTDIR}${PREFIX}/share/texmf-dist/doc/ttf2pk
	${INSTALL_DATA_DIR}	${DESTDIR}${PREFIX}/share/texmf-dist/ttf2tfm
	${LN} -fs		ttf2tfm \
				${DESTDIR}${PREFIX}/share/texmf-dist/ttf2pk
	${INSTALL_DATA_DIR}	${DESTDIR}${PREFIX}/share/texmf-dist/ttf2tfm/base
	${INSTALL_DATA}		${T2PSRC}/data/*.enc \
				${T2PSRC}/data/*.rpl \
				${T2PSRC}/data/*.sfd \
				${DESTDIR}${PREFIX}/share/texmf-dist/ttf2tfm/base
	${TOUCH}		${DESTDIR}${PREFIX}/share/texmf-dist/ttf2tfm/base/ttfonts.map

.include "../../mk/bsd.pkg.mk"
