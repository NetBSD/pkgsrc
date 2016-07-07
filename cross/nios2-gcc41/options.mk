# $NetBSD: options.mk,v 1.3 2016/07/07 13:26:16 rillig Exp $

### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.nios2-gcc
PKG_SUPPORTED_OPTIONS=	doc sysroot
PKG_SUGGESTED_OPTIONS=	sysroot

.include "../../mk/bsd.options.mk"

# See http://mail-index.netbsd.org/tech-toolchain/2011/03/21/msg001511.html
.if !empty(PKG_OPTIONS:Msysroot)
CFLAGS+=		-DTARGET_SYSTEM_ROOT=0 -DTARGET_SYSTEM_ROOT_RELOCATABLE
.endif

# conditional SUBST_CLASSES
.if empty(PKG_OPTIONS:Mdoc)
SUBST_CLASSES+=		nios
SUBST_STAGE.nios=	post-patch
SUBST_FILES.nios=	gcc/Makefile.in
SUBST_SED.nios=		-e s/@@DOC@@//
SUBST_SED.nios+=	-e s/@@INSTALL_HTML@@//
SUBST_SED.nios+=	-e s/@@INSTALL_PDF@@//
.else

# bin/tex is required
BUILD_DEPENDS+=		web2c-[0-9]*:../../print/web2c
BUILD_DEPENDS+=		tex-cm-[0-9]*:../../fonts/tex-cm
BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=		tex-pdftex-doc-[0-9]*:../../print/tex-pdftex-doc
BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
PLIST.doc=		yes

SUBST_CLASSES+=		nios
SUBST_STAGE.nios=	post-patch
SUBST_FILES.nios=	gcc/Makefile.in
SUBST_SED.nios=		-e s/@@DOC@@/doc/
SUBST_SED.nios+=	-e s/@@INSTALL_HTML@@/install-html/
SUBST_SED.nios+=	-e s/@@INSTALL_PDF@@/install-pdf/
.endif
