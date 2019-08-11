# $NetBSD: Makefile,v 1.67 2019/08/11 13:21:23 wiz Exp $

DISTNAME=		sather-1.2.3
PKGREVISION=		15
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=sather/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/sather/
COMMENT=		Compiler for the Sather object oriented programming language
#LICENSE=		gnu-gpl-v3 gnu-lgpl-v3

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake makeinfo pax perl:run

BUILD_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp

BUILD_TARGET=		full optional
INFO_FILES=		yes

REPLACE_PERL=		Browser/Web/ps2gif

SUBST_CLASSES+=		sather-configure
SUBST_STAGE.sather-configure=	pre-configure
SUBST_MESSAGE.sather-configure=	Configuring sources
SUBST_FILES.sather-configure=			\
	Boot/sacomp.code/Makefile		\
	Library/System/unix.sa			\
	System/Common/CONFIG.proto		\
	System/Platforms/${LOWER_OPSYS}/CONFIG	\
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
SUBST_VARS.sather-configure=	CC
SUBST_VARS.sather-configure+=	CFLAGS
SUBST_VARS.sather-configure+=	GMAKE
SUBST_VARS.sather-configure+=	PREFIX
SUBST_VARS.sather-configure+=	X11BASE
SUBST_SED.sather-configure+=	-e s:@GC_PREFIX@:${BUILDLINK_PREFIX.boehm-gc}:g
SUBST_SED.sather-configure+=	-e s:@TCL_PREFIX@:${BUILDLINK_PREFIX.tcl}:g
SUBST_SED.sather-configure+=	-e s:@TK_PREFIX@:${BUILDLINK_PREFIX.tk}:g
SUBST_VARS.sather-configure+=	LINKER_RPATH_FLAG
SUBST_VARS.sather-configure+=	COMPILER_RPATH_FLAG

INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1 share/doc/sather \
			lib/sather lib/sather/Bin share/emacs/site-lisp

post-patch:
	ln -s netbsd ${WRKSRC}/System/Platforms/dragonfly
	ln -s netbsd ${WRKSRC}/System/Platforms/darwin

post-build:
	cd ${WRKSRC}/Emacs &&						\
		makeinfo sather.texinfo && 				\
		makeinfo sather-tutorial.texinfo && 			\
		makeinfo sather-mode.texinfo
	${RM} -fr ${WRKSRC}/System/Platforms/dualgui/dual_gui_server.code

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/sacomp ${WRKSRC}/Bin/sabrowse	\
		${DESTDIR}${PREFIX}/lib/sather/Bin
	${INSTALL_SCRIPT} ${WRKSRC}/Bin/PP ${WRKSRC}/Bin/gen_html	\
		${WRKSRC}/Bin/saprep ${DESTDIR}${PREFIX}/lib/sather/Bin
	${INSTALL_SCRIPT} ${WRKSRC}/debian/bin-wrapper			\
		${DESTDIR}${PREFIX}/lib/sather/Bin
	 ${LN} -sf ../lib/sather/Bin/bin-wrapper ${DESTDIR}${PREFIX}/bin/sacomp
	 ${LN} -sf ../lib/sather/Bin/bin-wrapper ${DESTDIR}${PREFIX}/bin/sabrowse
	cd ${WRKSRC} && pax -s ',.*\.sav,,' -rw Library		\
		System/FORBID						\
		System/Debug						\
		System/Common/*.c System/Common/*.h			\
		System/Common/*.module System/Common/CONFIG		\
		System/Platforms/f77 System/Platforms/${LOWER_OPSYS}	\
		System/Platforms/X System/Platforms/dualgui		\
		System/Platforms/gui System/Platforms/tcltk		\
		Browser	${DESTDIR}${PREFIX}/lib/sather
	${FIND} ${DESTDIR}${PREFIX}/lib/sather				\
		-name \*.config -o -name Makefile 			\
		-o -name \*.orig -print | ${XARGS} ${RM} -f
	set -e; cd ${WRKSRC}/Emacs; for f in *.info *.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done
	cd ${WRKSRC}/Doc && pax -rw -s ',.*/man.*,,' .		\
		${DESTDIR}${PREFIX}/share/doc/sather
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sacomp.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sabrowse.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Emacs/*.el				\
		${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=return-type -Wno-comment -Wno-parentheses-equality
CWRAPPERS_APPEND.cc+=	-Wno-error=return-type -Wno-comment -Wno-parentheses-equality
.endif

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
