# $NetBSD: options.mk,v 1.2 2013/12/03 02:34:52 mef Exp $
### Set options
PKG_OPTIONS_VAR=        PKG_OPTIONS.nios2-gcc
PKG_SUPPORTED_OPTIONS=  doc sysroot
PKG_SUGGESTED_OPTIONS=      sysroot

.include "../../mk/bsd.options.mk"

# See http://mail-index.netbsd.org/tech-toolchain/2011/03/21/msg001511.html
.if !empty(PKG_OPTIONS:Msysroot)
CFLAGS+=		-DTARGET_SYSTEM_ROOT=0 -DTARGET_SYSTEM_ROOT_RELOCATABLE
.endif

# conditional SUBST_CLASSES
.if empty(PKG_OPTIONS:Mdoc)
post-patch:
	(cd ${WRKSRC};					\
	${MV}  gcc/Makefile.in gcc/Makefile.in.orig;	\
	${SED} '-e s/@@DOC@@//'				\
	       '-e s/@@INSTALL_HTML@@//'		\
	       '-e s/@@INSTALL_PDF@@//'			\
	gcc/Makefile.in.orig > gcc/Makefile.in;		\
	)
.else
# bin/tex is required
BUILD_DEPENDS+=		web2c-[0-9]*:../../print/web2c
BUILD_DEPENDS+=		tex-cm-[0-9]*:../../fonts/tex-cm
BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=		tex-pdftex-doc-[0-9]*:../../print/tex-pdftex-doc
BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
PLIST.doc=		yes
post-patch:
	(cd ${WRKSRC};					\
	${MV}  gcc/Makefile.in gcc/Makefile.in.orig;	\
	${SED} '-e s/@@DOC@@/doc/'			\
	       '-e s/@@INSTALL_HTML@@/install-html/'	\
	       '-e s/@@INSTALL_PDF@@/install-pdf/'	\
	gcc/Makefile.in.orig > gcc/Makefile.in;		\
	)
.endif
