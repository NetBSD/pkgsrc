# $NetBSD: Makefile,v 1.21 2003/03/09 19:17:56 jschauma Exp $

DISTNAME=		geomview-1.8.1
PKGREVISION=		1
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=geomview/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.geomview.org
COMMENT=		Interactive geometry viewing program

CONFLICTS=		ImageMagick-[0-9]*	# both have a program named 'animate'

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-xforms
CONFIGURE_ARGS+=	--with-opengl=${BUILDLINK_PREFIX.Mesa}
CONFIGURE_ARGS+=	--with-motif=${MOTIFBASE}
CPPFLAGS+=		-Dunix -Dalloca=__builtin_alloca

INFO_FILES=		geomview

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--enable-fstropen-1
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/geomview.pdf			\
	${PREFIX}/share/doc/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/example*				\
	${PREFIX}/share/examples/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html 			\
	${PREFIX}/share/doc/html/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/geomview/pix
	${INSTALL_DATA} ${WRKSRC}/doc/html/pix/*			\
	${PREFIX}/share/doc/html/geomview/pix

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
