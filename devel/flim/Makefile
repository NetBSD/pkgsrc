# $NetBSD: Makefile,v 1.9 2003/04/23 16:59:51 jmc Exp $

DISTNAME=	flim-1.14.5
PKGREVISION=	2
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
TEXINFO_REQD=	4.5

pre-build:
	@cd ${WRKSRC}; \
	for i in mime-en mime-ja; do \
		${RM} -f $${i}.info; \
		${CP} $${i}.texi $${i}.texi.orig; \
		${LOCALBASE}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi; \
		${MAKEINFO} --force --no-validate --no-split $${i}.texi; \
	done

pre-install:
	${INSTALL_DATA} ${WRKSRC}/mime-*.info ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
