# $NetBSD: Makefile,v 1.6 2008/10/11 09:31:55 uebayasi Exp $
#

DISTNAME=	psvn.el
PKGNAME=	psvn-${VER}
CATEGORIES=	devel editors scm
MASTER_SITES=	http://svn.collab.net/viewvc/*checkout*/svn/trunk/contrib/client-side/emacs/psvn.el?revision=${VER}&file=
DIST_SUBDIR=	psvn-${VER}
EXTRACT_SUFX=	# empty
FETCH_BEFORE_ARGS+=  -o ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xsteve.at/prg/emacs/
COMMENT=	Subversion interface for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		25241
WRKSRC=		${WRKDIR}

.include "../../editors/emacs/modules.mk"

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:S/^${PREFIX}\///}

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/psvn.el ${WRKDIR}

do-build:
	${EMACS_BIN} --no-init-file -batch -f batch-byte-compile \
		${WRKDIR}/psvn.el

do-install:
	${INSTALL_DATA} ${WRKDIR}/psvn.el ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKDIR}/psvn.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
