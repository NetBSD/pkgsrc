# $NetBSD: Makefile,v 1.6 2003/04/13 03:55:51 uebayasi Exp $

DISTNAME=	semi-1.14.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	apel>=10.3:../../devel/apel
DEPENDS+=	flim>=1.6:../../devel/flim
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

INFO_FILES=	mime-ui-en.info mime-ui-ja.info

pre-build:
	${RM} -f ${WRKSRC}/mime-ui-*.info
	${LOCALBASE}/bin/qkc -eu ${WRKSRC}/mime-ui-*.texi
	cd ${WRKSRC} && ${MAKEINFO} --no-validate --no-split mime-ui-en.texi
	cd ${WRKSRC} && ${MAKEINFO} --no-validate --no-split mime-ui-ja.texi

post-install:
	${INSTALL_DATA} ${WRKSRC}/mime-ui-en.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/mime-ui-ja.info ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
