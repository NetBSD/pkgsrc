# $NetBSD: Makefile,v 1.43 2019/08/11 13:21:20 wiz Exp $

DISTNAME=		gforth-0.7.3
PKGREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}
MASTER_SITES+=		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language
LICENSE=		gnu-gpl-v3

# This package claims to specifically support the following arches:
#    alpha arm hppa i386 ia64 m68k mips powerpc sparc x86_64
# and it has a generic config that should work for all random other
# processors as long as they have IEEE floats. So, we'll explicitly
# exclude vax and allow anything else.
NOT_FOR_PLATFORM=	*-*-vax

EXTRACT_USING=		bsdtar

INFO_FILES=		yes

GNU_CONFIGURE=		YES

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake aclocal m4
USE_TOOLS+=		makeinfo gzip
USE_TOOLS+=		perl:build

MAKE_JOBS_SAFE=		no # fresh Gforth is required to build doc
BUILD_TARGET=		all info # doc
TEST_TARGET=		check

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
CFLAGS+=		-Dunix
BUILDLINK_TRANSFORM+=	rm:-m486 # let it build with contemporary GCC
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			infodir=${PREFIX:Q}/${PKGINFODIR:Q}		\
			mandir=${PREFIX:Q}/${PKGMANDIR:Q}

INSTALLATION_DIRS=	share/emacs/site-lisp

# Kernel image filename is arch dependent
KERNEL_FI_cmd=								\
	if ${TEST} ! -f ${WRKSRC}/Makefile; then			\
		${ECHO} "__nonexistent__";				\
		exit 0;							\
	fi;								\
	cd ${WRKSRC} &&							\
	{ ${ECHO} 'prkern:';						\
	  ${ECHO} '	@${ECHO} $$(kernel_fi)';			\
	  ${ECHO} ;							\
	  ${CAT} Makefile; } | ${MAKE_PROGRAM} -f - prkern
PLIST_SUBST+=	KERNEL_FI=${KERNEL_FI_cmd:sh:Q}

# Owing to https://gcc.gnu.org/bugzilla/show_bug.cgi?id=31152,
# demand at least gcc 4.3 for arm.
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_ARCH:Marm*) || !empty(MACHINE_ARCH:Mearm*)
.if !empty(PKGSRC_COMPILER:Mgcc)
GCC_REQD+=	4.3
.endif
.endif

# XXX Need test.
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libffcall/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
