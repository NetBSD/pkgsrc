# $NetBSD: Makefile,v 1.15 2011/01/13 13:39:15 wiz Exp $

DISTNAME=	texlive-20100720-source
PKGNAME=	web2c-2010
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

CONFLICTS+=	ja-ptex-bin-[0-9]*
CONFLICTS+=	teTeX-bin<=3.0nb28
CONFLICTS+=	texlive-tetex<2010

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/obsdcompat \
			${DISTNAME}/texk/ptexenc \
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
CONFIGURE_ARGS+=	--with-system-xpdf
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
LIBTOOL_OVERRIDE=	../*/libtool */libtool

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/libs/obsdcompat \
		${WRKDIR}/${DISTNAME}/texk/ptexenc \
		${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"

post-install:
	${LN} -sf cweb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ctangle.1
	${LN} -sf cweb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cweave.1
	${LN} -sf mf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mf-nowin.1
	${LN} -sf dvicopy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/odvicopy.1
	${LN} -sf dvitype.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/odvitype.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdftex.1

.include "../../mk/bsd.pkg.mk"
