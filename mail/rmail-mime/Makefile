# $NetBSD: Makefile,v 1.9 2008/10/11 09:31:57 uebayasi Exp $
#

DISTNAME=	rmail-mime-1.13.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/rmail-mime/

MAINTAINER=	jschauma@NetBSD.org
COMMENT=	MIME-capabilities for RMAIL in Emacs

DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi>=1.14.4:../../devel/semi

PKG_DESTDIR_SUPPORT=	user-destdir

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
