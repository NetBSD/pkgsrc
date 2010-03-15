# $NetBSD: Makefile,v 1.2 2010/03/15 09:53:42 jmmv Exp $
#

DISTNAME=	monotone-0.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-el-/}
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/0.47/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Emacs packages to work with the monotone VCS

PKG_DESTDIR_SUPPORT=	user-destdir

EL_FILES=	monotone monotone-nav

do-build:
.for f in ${EL_FILES}
	${EMACS_BIN} --no-init-file --no-site-file --batch \
	    --directory ${WRKSRC}/contrib \
	    -f batch-byte-compile ${WRKSRC}/contrib/${f}.el
.endfor

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
.for f in ${EL_FILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f}.el \
	    ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f}.elc \
	    ${DESTDIR}${EMACS_LISPPREFIX}
.endfor

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
