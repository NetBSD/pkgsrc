# $NetBSD: Makefile,v 1.1.1.1 2002/05/04 00:45:28 jtb Exp $

DISTNAME=		sather-1.2.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=sather/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/sather/index.html
COMMENT=		Compiler for the Sather object oriented programming language

DEPENDS+=		boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=		tcl-8.3.*:../../lang/tcl
DEPENDS+=		tk-8.3.*:../../x11/tk

USE_GMAKE=		# defined

ALL_TARGET=		full optional

GC_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		GC_PREFIX=boehm-gc
TCL_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TCL_PREFIX=tcl
TK_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TK_PREFIX=tk

INFO_FILES=		sather.info sather-tutorial.info sather-mode.info

do-configure:
	for f in ${WRKSRC}/Boot/sacomp.code/Makefile			\
		${WRKSRC}/Library/System/unix.sa			\
		${WRKSRC}/System/Common/CONFIG.proto			\
		${WRKSRC}/System/Platforms/netbsd/CONFIG		\
		${WRKSRC}/System/Platforms/X/Platform.module		\
		${WRKSRC}/debian/bin-wrapper				\
		${WRKSRC}/Browser/Web/convert-1.1			\
		${WRKSRC}/Browser/Web/gen_html_class_index		\
		${WRKSRC}/Browser/Web/gen_html_sa_files			\
		${WRKSRC}/Browser/Web/gen_html_shortflat		\
		${WRKSRC}/Browser/Web/gen_html_top_level		\
		${WRKSRC}/Browser/Web/gen_mml_sa_files			\
		${WRKSRC}/Browser/Web/gen_mml_shortflat			\
		${WRKSRC}/Browser/Web/graph2dot; do			\
	${SED} -e 's:@CC@:${CC}:g'					\
		-e 's:@CFLAGS@:${CFLAGS}:g'				\
		-e 's:@GMAKE@:${GMAKE}:g'				\
		-e 's:@PREFIX@:${PREFIX}:g'				\
		-e 's:@X11BASE@:${X11BASE}:g'				\
		-e 's:@GC_PREFIX@:${GC_PREFIX}:g'			\
		-e 's:@TCL_PREFIX@:${TCL_PREFIX}:g'			\
		-e 's:@TK_PREFIX@:${TK_PREFIX}:g'			\
		$$f > $$f.tmp && ${MV} -f $$f.tmp $$f;			\
	done

post-build:
	cd ${WRKSRC}/Emacs; ${MAKEINFO} sather.texinfo; 		\
		${MAKEINFO} sather-tutorial.texinfo; 			\
		${MAKEINFO} sather-mode.texinfo

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sather
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/sather/Bin
	cd ${WRKSRC}/Bin;						\
	${INSTALL_PROGRAM} sacomp sabrowse ${PREFIX}/lib/sather/Bin;	\
	${INSTALL_SCRIPT} PP gen_html saprep ${PREFIX}/lib/sather/Bin
	${INSTALL_SCRIPT} ${WRKSRC}/debian/bin-wrapper			\
		${PREFIX}/lib/sather/Bin
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/Library		\
		${WRKSRC}/System
	cd ${PREFIX}/bin;						\
		 ${LN} -sf ../lib/sather/Bin/bin-wrapper sacomp;	\
		 ${LN} -sf ../lib/sather/Bin/bin-wrapper sabrowse;	\
	cd ${WRKSRC} && ${PAX} -rw Library System/FORBID System/Debug	\
		System/Common/*.c System/Common/*.h			\
		System/Common/*.module System/Common/CONFIG		\
		System/Platforms/f77 System/Platforms/netbsd		\
		System/Platforms/X System/Platforms/dualgui		\
		System/Platforms/gui System/Platforms/tcltk		\
		Browser	${PREFIX}/lib/sather
	${FIND} ${PREFIX}/lib/sather -name \*.config -o -name Makefile 	\
		-o -name \*.orig | ${XARGS} ${RM} -f
	${INSTALL_DATA} ${WRKSRC}/Emacs/*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sather
	cd ${WRKSRC}/Doc && ${PAX} -rw . ${PREFIX}/share/doc/sather
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sacomp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sabrowse.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/Emacs/*.el ${PREFIX}/share/emacs/site-lisp

# should fix this
post-install:
	${RM} -fr ${PREFIX}/lib/sather/System/Platforms/dualgui/dual_gui_server.code/

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
