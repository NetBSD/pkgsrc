# $NetBSD: Makefile,v 1.21 2004/10/03 00:15:02 tv Exp $

DISTNAME=		sather-1.2.1
PKGREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=sather/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/directory/devel/prog/sather.html
COMMENT=		Compiler for the Sather object oriented programming language

USE_BUILDLINK3=		yes
USE_X11=		# defined
USE_GNU_TOOLS+=		make

ALL_TARGET=		full optional

USE_MAKEINFO=		YES
INFO_FILES=		sather.info sather-tutorial.info sather-mode.info

REPLACE_PERL=		Browser/Web/ps2gif

SUBST_CLASSES+=		sather-configure
SUBST_STAGE.sather-configure=	post-buildlink
SUBST_MESSAGE.sather-configure=	"Configuring sources"
SUBST_FILES.sather-configure=			\
	Boot/sacomp.code/Makefile		\
	Library/System/unix.sa			\
	System/Common/CONFIG.proto		\
	System/Platforms/netbsd/CONFIG		\
	System/Platforms/X/Platform.module	\
	debian/bin-wrapper			\
	Browser/Web/convert-1.1			\
	Browser/Web/gen_html_class_index	\
	Browser/Web/gen_html_sa_files		\
	Browser/Web/gen_html_shortflat		\
	Browser/Web/gen_html_top_level		\
	Browser/Web/gen_mml_sa_files		\
	Browser/Web/gen_mml_shortflat		\
	Browser/Web/graph2dot
SUBST_SED.sather-configure=					\
	-e 's:@CC@:${CC}:g'					\
	-e 's:@CFLAGS@:${CFLAGS}:g'				\
	-e 's:@GMAKE@:${GMAKE}:g'				\
	-e 's:@PREFIX@:${PREFIX}:g'				\
	-e 's:@X11BASE@:${X11BASE}:g'				\
	-e 's:@GC_PREFIX@:${BUILDLINK_PREFIX.boehm-gc}:g'	\
	-e 's:@TCL_PREFIX@:${BUILDLINK_PREFIX.tcl}:g'		\
	-e 's:@TK_PREFIX@:${BUILDLINK_PREFIX.tk}:g'		\
	-e 's:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g'	\
	-e 's:@COMPILER_RPATH_FLAG@:${COMPILER_RPATH_FLAG}:g'

post-build:
	cd ${WRKSRC}/Emacs; ${MAKEINFO} sather.texinfo; 		\
		${MAKEINFO} sather-tutorial.texinfo; 			\
		${MAKEINFO} sather-mode.texinfo
	${RM} -fr ${WRKSRC}/System/Platforms/dualgui/dual_gui_server.code

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sather
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/sather/Bin
	cd ${WRKSRC}/Bin;						\
	${INSTALL_PROGRAM} sacomp sabrowse ${PREFIX}/lib/sather/Bin;	\
	${INSTALL_SCRIPT} PP gen_html saprep ${PREFIX}/lib/sather/Bin
	${INSTALL_SCRIPT} ${WRKSRC}/debian/bin-wrapper			\
		${PREFIX}/lib/sather/Bin
	cd ${PREFIX}/bin;						\
		 ${LN} -sf ../lib/sather/Bin/bin-wrapper sacomp;	\
		 ${LN} -sf ../lib/sather/Bin/bin-wrapper sabrowse;	\
	cd ${WRKSRC} && ${PAX} -s ',.*\.sav,,' -rw Library		\
		System/FORBID						\
		System/Debug						\
		System/Common/*.c System/Common/*.h			\
		System/Common/*.module System/Common/CONFIG		\
		System/Platforms/f77 System/Platforms/netbsd		\
		System/Platforms/X System/Platforms/dualgui		\
		System/Platforms/gui System/Platforms/tcltk		\
		Browser	${PREFIX}/lib/sather
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/sather/Library \
		${PREFIX}/lib/sather/System
	${FIND} ${PREFIX}/lib/sather -name \*.config -o -name Makefile 	\
		-o -name \*.orig -print | ${XARGS} ${RM} -f
	${INSTALL_DATA} ${WRKSRC}/Emacs/*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sather
	cd ${WRKSRC}/Doc && ${PAX} -rw -s ',.*/man.*,,' .		\
		${PREFIX}/share/doc/sather
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sacomp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sabrowse.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/Emacs/*.el ${PREFIX}/share/emacs/site-lisp

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
