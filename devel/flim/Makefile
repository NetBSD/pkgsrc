# $NetBSD: Makefile,v 1.6 2003/04/13 04:14:23 uebayasi Exp $

DISTNAME=	flim-1.14.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/flim/flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/FLIM/
COMMENT=	Emacs lisp library for message representation/encoding

DEPENDS+=	apel>=9.22:../../devel/apel
BUILD_DEPENDS+=	qkc-*:../../converters/qkc

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=     elc
INSTALL_TARGET= install
.else   # ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=     package
INSTALL_TARGET= install-package
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREX:C|/lisp$||}
.endif

INFO_FILES=	mime-en.info mime-ja.info

pre-build:
	${RM} -f ${WRKSRC}/mime-*.info
	${LOCALBASE}/bin/qkc -eu ${WRKSRC}/mime-*.texi
	cd ${WRKSRC} && ${MAKEINFO} --no-validate --no-split mime-en.texi
	cd ${WRKSRC} && ${MAKEINFO} --no-validate --no-split mime-ja.texi

pre-install:
	${INSTALL_DATA} ${WRKSRC}/mime-*.info ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
