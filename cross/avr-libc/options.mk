# $NetBSD: options.mk,v 1.3 2019/06/08 10:53:26 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.avr-libc
PKG_SUPPORTED_OPTIONS+=		doc
PKG_SUGGESTED_OPTIONS+=		doc
PLIST_VARS+=			doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-doc
BUILD_DEPENDS+=		doxygen>=1.8.9.1.nb1:../../devel/doxygen
BUILD_DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
BUILD_DEPENDS+=		tex-wasysym-[0-9]*:../../fonts/tex-wasysym
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm
BUILD_DEPENDS+=		tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
BUILD_DEPENDS+=		tex-adjustbox-[0-9]*:../../print/tex-adjustbox
BUILD_DEPENDS+=		tex-caption-[0-9]*:../../print/tex-caption
BUILD_DEPENDS+=		tex-collectbox-[0-9]*:../../print/tex-collectbox
BUILD_DEPENDS+=		tex-colortbl-[0-9]*:../../print/tex-colortbl
BUILD_DEPENDS+=		tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
BUILD_DEPENDS+=		tex-float-[0-9]*:../../print/tex-float
BUILD_DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
BUILD_DEPENDS+=		tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
BUILD_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		tex-multirow-[0-9]*:../../print/tex-multirow
BUILD_DEPENDS+=		tex-natbib-[0-9]*:../../print/tex-natbib
BUILD_DEPENDS+=		tex-pgf-[0-9]*:../../print/tex-pgf
BUILD_DEPENDS+=		tex-sectsty-[0-9]*:../../print/tex-sectsty
BUILD_DEPENDS+=		tex-tabu-[0-9]*:../../print/tex-tabu
BUILD_DEPENDS+=		tex-tocloft-[0-9]*:../../print/tex-tocloft
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=		tex-xkeyval-[0-9]*:../../print/tex-xkeyval
BUILD_DEPENDS+=		fig2dev-[0-9]*:../../print/fig2dev
BUILD_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk

post-extract:
	${MKDIR} ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-setup.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-wiring.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-wiring2.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/stdiodemo/stdiodemo-setup.jpg ${WRKSRC}/doc/api/latex_src

post-install:
	${INSTALL_DATA} \
                ${WRKSRC}/LICENSE \
                ${WRKSRC}/AUTHORS \
                ${DESTDIR}${PREFIX}/share/doc/avr-libc
	## delete following or similar files, which includes PATH at build time.
	##_usr_pkgsrc_cross_avr-libc_work_avr-libc-1.8.0_libc_string_.3
	${RM} ${DESTDIR}${PREFIX}/share/doc/avr-libc/man/man3/*${PKGVERSION_NOREV}*
.  for f in Makefile demo.c demo.bin demo.hex demo.pdf demo.srec
	${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/${f} \
		${DESTDIR}${PREFIX}/share/doc/avr-libc/examples/demo
.  endfor


PLIST.doc=		yes

.else
CONFIGURE_ARGS+=	--disable-doc
.endif
