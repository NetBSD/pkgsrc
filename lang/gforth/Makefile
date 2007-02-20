# $NetBSD: Makefile,v 1.24 2007/02/20 19:04:12 wiz Exp $

DISTNAME=		gforth-0.6.2
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}
MASTER_SITES+=		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc

GNU_CONFIGURE=		YES

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
CFLAGS+=		-Dunix
INFO_FILES=		# PLIST
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			infodir=${PREFIX:Q}/${PKGINFODIR:Q}		\
			mandir=${PREFIX:Q}/${PKGMANDIR:Q}

TEST_TARGET=	test

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
.include "../../devel/ffcall/buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
