# $NetBSD: Makefile,v 1.32 2012/09/15 10:05:19 obache Exp $

DISTNAME=		gforth-0.7.0
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}
MASTER_SITES+=		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language
LICENSE=		gnu-gpl-v3

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc
ONLY_FOR_PLATFORM+=	*-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir
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

# XXX Need test.
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
