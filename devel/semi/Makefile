# $NetBSD: Makefile,v 1.12 2004/09/10 17:10:24 uebayasi Exp $

DISTNAME=	semi-1.14.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	${PKGNAME_PREFIX}apel>=10.3:../../devel/apel
DEPENDS+=	${PKGNAME_PREFIX}flim>=1.6:../../devel/flim
#BUILD_DEPENDS+=	${PKGNAME_PREFIX}w3-*:../../www/w3
BUILD_DEPENDS+=	${PKGNAME_PREFIX}bbdb-*:../../misc/bbdb
BUILD_DEPENDS+=	qkc-*:../../converters/qkc

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=     elc
INSTALL_TARGET= install
.else   # ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=     package
INSTALL_TARGET= install-package
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

USE_MAKEINFO=	YES
INFO_FILES=	mime-ui-en.info mime-ui-ja.info

pre-build:
	@cd ${WRKSRC}; \
	for i in mime-ui-en mime-ui-ja; do \
		${RM} -f $${i}.info; \
		${CP} $${i}.texi $${i}.texi.orig; \
		${LOCALBASE}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi; \
		${MAKEINFO} --force --no-validate --no-split $${i}.texi; \
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/mime-ui-en.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/mime-ui-ja.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
