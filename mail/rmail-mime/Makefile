# $NetBSD: Makefile,v 1.14 2013/02/17 19:18:06 dholland Exp $
#

DISTNAME=	rmail-mime-1.13.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/rmail-mime/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MIME-capabilities for RMAIL in Emacs

DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi>=1.14.4:../../devel/semi

.include "../../editors/emacs/modules.mk"

SITE_LISP=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	SITE_LISP=${SITE_LISP:Q}

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rmail-mime.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.el ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
