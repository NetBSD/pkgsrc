# $NetBSD: Makefile,v 1.92 2026/01/04 10:44:54 wiz Exp $

DISTNAME=	xpaint-3.1.4
PKGREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	bash gmake gunzip pkg-config

MAKE_JOBS_SAFE=	no

REPLACE_BASH=	share/bin/imgmerge share/bin/xpaint_ocr

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

SUBST_CLASSES+=		ln
SUBST_STAGE.ln=		pre-configure
SUBST_MESSAGE.ln=	Linking to libXaw3dXft include directory.
SUBST_FILES.ln=		Makefile.am
SUBST_SED.ln=		-e 's|/usr/include/X11/Xaw3dxft|${WRKDIR}/.buildlink/include/X11/Xaw3dxft|'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	configure.ac Makefile.am xpaintrw/Makefile.am
SUBST_SED.paths=	-e 's|/usr/bin/libtool|libtool --tag=CC|'
SUBST_SED.paths+=	-e 's|/etc/X11/app-defaults|${PREFIX}/lib/X11/app-defaults|'
SUBST_SED.paths+=	-e 's|freetype2/config/ftheader.h|freetype2/freetype/config/ftheader.h|'

SUBST_CLASSES+=		ctype
SUBST_STAGE.ctype=	pre-build
SUBST_MESSAGE.ctype=	Fixing isspace arguments.
SUBST_SED.ctype+=	-e 's|isspace(|isspace((unsigned char)|'
SUBST_FILES.ctype+=	help.c
SUBST_FILES.ctype+=	main.c
SUBST_FILES.ctype+=	misc.c
SUBST_FILES.ctype+=	msgedit.c
SUBST_FILES.ctype+=	preproc.c
SUBST_FILES.ctype+=	print.c
SUBST_FILES.ctype+=	substads.c
SUBST_FILES.ctype+=	xpaintrw/readWritePS.c

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

pre-install:
	for file in ${WRKSRC}/bitmaps/toolicons/*.xpm.gz ; do \
		${GUNZIP_CMD} $$file ; \
	done

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXaw3dXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
