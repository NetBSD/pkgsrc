# $NetBSD: Makefile,v 1.19 2004/10/03 00:15:01 tv Exp $

DISTNAME=		gforth-0.6.2
PKGREVISION=	1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}
MASTER_SITES+=		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
CFLAGS+=		-Dunix
INFO_FILES=		gforth.info vmgen.info

PLIST_SRC=	${WRKDIR}/PLIST

TEST_TARGET=	test

# Kernel image filename is arch dependent
KERNEL_FI=	`cd ${WRKSRC} && (${ECHO} 'prkern:'; ${ECHO} '	@${ECHO} $$(kernel_fi)'; ${ECHO}; ${CAT} Makefile) | ${MAKE} -f - prkern`

# XXX Need test.
#.include "../../devel/dlcompat/buildlink3.mk"

post-build:
	@${ECHO}; ${ECHO} building PLIST...
	@k=${KERNEL_FI} && ${ECHO} "using kernel image: $$k" &&	\
	${SED} -e "s/@KERNEL_FI@/$$k/g" <${PKGDIR}/PLIST >${PLIST_SRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp

.include "../../devel/ffcall/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
