# $NetBSD: Makefile,v 1.20 2008/04/13 22:12:56 wiz Exp $
#

DISTNAME=	python-mode-1.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-mode/
COMMENT=	Emacs mode for editing python files

PKG_DESTDIR_SUPPORT=	user-destdir

ELISP_FILES=	python-mode.el
# Could be installed as well, but what about pycomplete.py?
#ELISP_FILES+=	doctest-mode.el pycomplete.el

# Note that XEmacs >=21.4.4 includes a python-mode in the prog-modes
# package. Also, python-mode does not appear to work as is with XEmacs 21.1
EMACS_VERSIONS_ACCEPTED= emacs22 emacs22nox emacs21 emacs21nox emacs20

.include "../../mk/emacs.mk"

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:S/^${PREFIX}\///}

do-build:
	for file in ${ELISP_FILES}; do \
		${EMACS_BIN} --no-init-file -batch \
		-f batch-byte-compile ${WRKSRC}/$${file}; \
	done

do-install:
	for file in ${ELISP_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} \
			${DESTDIR}${EMACS_LISPPREFIX}; \
		${INSTALL_DATA} ${WRKSRC}/$${file}c \
			${DESTDIR}${EMACS_LISPPREFIX}; \
	done
#	${INSTALL_DATA} ${WRKSRC}/pycomplete.py ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
