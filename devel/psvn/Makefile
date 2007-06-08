# $NetBSD: Makefile,v 1.3 2007/06/08 23:35:32 wiz Exp $
#

DISTNAME=	psvn.el
PKGNAME=	psvn-${VER}
CATEGORIES=	devel editors scm
MASTER_SITES=	http://www.xsteve.at/prg/emacs/
DIST_SUBDIR=	psvn-${VER}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
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
