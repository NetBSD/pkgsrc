# $NetBSD: Makefile,v 1.10 2010/06/13 22:45:18 wiz Exp $

DISTNAME=	texlive-20091011-source
PKGNAME=	web2c-2009
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

CONFLICTS+=	teTeX-bin<=3.0nb28

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/obsdcompat \
			${DISTNAME}/libs/xpdf \
			${DISTNAME}/texk/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex yacc pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-xetex
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--without-mf-x-toolkit
CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-libpng \
			--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
			--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/libs/obsdcompat \
		${WRKDIR}/${DISTNAME}/libs/xpdf \
		${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"

post-install:
	${LN} -sf cweb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ctangle.1
	${LN} -sf cweb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cweave.1
	${LN} -sf mf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mf-nowin.1
	${LN} -sf dvicopy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/odvicopy.1
	${LN} -sf dvitype.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/odvitype.1

.include "../../mk/bsd.pkg.mk"
