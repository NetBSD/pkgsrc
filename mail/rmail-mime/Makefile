# $NetBSD: Makefile,v 1.5 2005/08/28 04:25:30 uebayasi Exp $
#

DISTNAME=	rmail-mime-1.13.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/rmail-mime/

MAINTAINER=	jschauma@NetBSD.org
COMMENT=	MIME-capabilities for RMAIL in Emacs

DEPENDS=	${EMACS_PKGNAME_PREFIX}semi>=1.14.4:../../devel/semi

.include "../../mk/emacs.mk"

SITE_LISP=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rmail-mime.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.el ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.elc ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
