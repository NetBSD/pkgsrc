# $NetBSD: Makefile,v 1.15 2003/11/03 18:35:24 jmmv Exp $

DISTNAME=		gforth-0.5.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc

GNU_CONFIGURE=		YES
# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
CFLAGS+=		-Dunix
INFO_FILES=		gforth.info

PLIST_SRC=	${WRKDIR}/PLIST

# kernel image filename is arch dependent
KERNEL_FI=	`cd ${WRKSRC} && (${ECHO} 'prkern:'; ${ECHO} '	@${ECHO} $$(kernel_fi)'; ${ECHO}; ${CAT} Makefile) | ${MAKE} -f - prkern`

post-build:
	@${ECHO}; ${ECHO} building PLIST...
	@k=${KERNEL_FI} && ${ECHO} "using kernel image: $$k" &&	\
	${SED} -e "s/@KERNEL_FI@/$$k/g" <${PKGDIR}/PLIST >${PLIST_SRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
