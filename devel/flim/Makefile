# $NetBSD: Makefile,v 1.23 2006/03/30 23:55:38 jlam Exp $

DISTNAME=	flim-1.14.7
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/flim/flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/FLIM/
COMMENT=	Emacs lisp library for message representation/encoding

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215
EMACS_MODULES=	base

.include "../../mk/emacs.mk"

BUILD_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

.if ${EMACS_FLAVOR} == "emacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=9.22:../../devel/apel
BUILD_TARGET=	elc
INSTALL_TARGET= install
.else	# ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=	package
INSTALL_TARGET= install-package
MAKEFLAGS+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

EVAL_PREFIX+=	QKC_PREFIX=qkc
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST
TEXINFO_REQD=	4.5

post-build:
	@cd ${WRKSRC}; for i in mime-en mime-ja; do			\
		${RM} -f $${i}.info*;					\
		${CP} $${i}.texi $${i}.texi.orig;			\
		${QKC_PREFIX}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi;	\
		makeinfo --force --no-validate $${i}.texi;		\
	done

post-install:
	cd ${WRKSRC}; for f in mime-*.info mime-*.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
	done

.include "../../mk/bsd.pkg.mk"
