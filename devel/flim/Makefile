# $NetBSD: Makefile,v 1.16 2004/12/03 15:14:54 wiz Exp $

DISTNAME=	flim-1.14.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/flim/flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/FLIM/
COMMENT=	Emacs lisp library for message representation/encoding

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215
.include "../../mk/emacs.mk"

DEPENDS+=	${PKGNAME_PREFIX}apel>=9.22:../../devel/apel
BUILD_DEPENDS+=	qkc-*:../../converters/qkc

.if ${EMACS_FLAVOR} == "emacs"
BUILD_TARGET=     elc
INSTALL_TARGET= install
.else   # ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=     package
INSTALL_TARGET= install-package
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

USE_MAKEINFO=	YES
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

.include "../../mk/bsd.pkg.mk"
