# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:52 jlam Exp $
#

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=		ttf2pk-1.3.1
CATEGORIES=		print

MAINTAINER=		bernhard@SDG.de,hubertf@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		TrueType to TeX PK font converter

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-kpathsea-dir=${PREFIX}/lib

T2PSRC=			${WRKSRC}/contrib/ttf2pk
CONFIGURE_DIRS+=	${T2PSRC}
BUILD_DIRS=		${T2PSRC}

BUILD_TARGET=		depend all

USE_LIBTOOL=		# defined
USE_TOOLS+=		autoconf

TEXMF=			${PREFIX}/share/texmf
INSTALLATION_DIRS=	bin man/man1

pre-configure:
			cd ${T2PSRC}; autoconf

do-install:
			${INSTALL_PROGRAM}	${T2PSRC}/ttf2pk \
						${T2PSRC}/ttf2tfm \
						${PREFIX}/bin
			${INSTALL_DATA}		${T2PSRC}/ttf2pk.1 \
						${T2PSRC}/ttf2tfm.1 \
						${PREFIX}/man/man1
			${INSTALL_DATA_DIR}	${TEXMF}/doc/ttf2pk
			${INSTALL_DATA}		${T2PSRC}/BUGS \
						${T2PSRC}/README \
						${T2PSRC}/TODO \
						${T2PSRC}/ttf2pk.doc \
						${T2PSRC}/data/ttfonts.map \
						${TEXMF}/doc/ttf2pk
			${INSTALL_DATA_DIR}	${TEXMF}/ttf2tfm
			${LN} -fs		ttf2tfm \
						${TEXMF}/ttf2pk
			${INSTALL_DATA_DIR}	${TEXMF}/ttf2tfm/base
			${INSTALL_DATA}		${T2PSRC}/data/*.enc \
						${T2PSRC}/data/*.rpl \
						${T2PSRC}/data/*.sfd \
						${TEXMF}/ttf2tfm/base
			${TOUCH}		${TEXMF}/ttf2tfm/base/ttfonts.map
			${PREFIX}/bin/mktexlsr

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
