# $NetBSD: Makefile,v 1.10 2004/12/05 05:55:51 ben Exp $
#

DISTNAME=	python-mode-4.6.54
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mode/}
DISTFILES=	python-mode.el

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/project/python-mode/
COMMENT=	Emacs mode for editing python files

# Note that XEmacs >=21.4.4 includes a python-mode in the prog-modes
# package. Also, python-mode does not appear to work as is with XEmacs 21.1
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox emacs20

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	python-mode-20041204

.include "../../mk/emacs.mk"

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/python-mode.el ${WRKDIR}

do-build:
	${EMACS_BIN} --no-init-file -batch 		\
	-f batch-byte-compile ${WRKDIR}/python-mode.el

do-install:
	${INSTALL_DATA} ${WRKDIR}/python-mode.el ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKDIR}/python-mode.elc ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
