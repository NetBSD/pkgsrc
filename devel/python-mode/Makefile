# $NetBSD: Makefile,v 1.6 2003/11/08 08:59:45 xtraeme Exp $
#

DISTNAME=	python-mode-4.6
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://www.python.org/emacs/python-mode/
DISTFILES=	python-mode.el

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/emacs/python-mode/
COMMENT=	Emacs mode for editing python files

# Note that XEmacs >=21.4.4 includes a python-mode in the prog-modes
# package. Also, python-mode does not appear to work as is with XEmacs 21.1
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox emacs20

.include "../../mk/emacs.mk"

do-extract:
	${CP} ${DISTDIR}/python-mode.el ${WRKDIR}; done

do-build:
	${EMACS_BIN} --no-init-file -batch 		\
	-f batch-byte-compile ${WRKDIR}/python-mode.el

do-install:
	${INSTALL_DATA} ${WRKDIR}/python-mode.el ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKDIR}/python-mode.elc ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
