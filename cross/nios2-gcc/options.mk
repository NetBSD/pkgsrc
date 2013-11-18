# $NetBSD: options.mk,v 1.1 2013/11/18 06:41:27 mef Exp $
### Set options
PKG_OPTIONS_VAR=        PKG_OPTIONS.nios2-gcc
PKG_SUPPORTED_OPTIONS=  doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

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
