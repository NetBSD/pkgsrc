# $NetBSD: Makefile,v 1.1.1.1 2007/05/29 15:40:18 taca Exp $
#

DISTNAME=	psvn.el
PKGNAME=	psvn-${VER}
CATEGORIES=	devel editors
MASTER_SITES=	http://www.xsteve.at/prg/emacs/
DIST_SUBDIR=	psvn-${VER}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-useres@NetBSD.org
HOMEPAGE=	http://www.xsteve.at/prg/emacs/
COMMENT=	Subversion interface for Emacs

VER=		25168
WRKSRC=		${WRKDIR}

.include "../../mk/emacs.mk"

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:S/^${PREFIX}\///}

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/psvn.el ${WRKDIR}

do-build:
	${EMACS_BIN} --no-init-file -batch -f batch-byte-compile \
		${WRKDIR}/psvn.el

do-install:
	${INSTALL_DATA} ${WRKDIR}/psvn.el ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKDIR}/psvn.elc ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
