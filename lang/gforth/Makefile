# $NetBSD: Makefile,v 1.10 2002/02/18 15:14:25 seb Exp $

DISTNAME=		gforth-0.5.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}

MAINTAINER=		simonb@netbsd.org
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k

GNU_CONFIGURE=		YES
# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
