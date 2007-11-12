# $NetBSD: Makefile,v 1.26 2007/11/12 05:34:10 uebayasi Exp $
#

DISTNAME=	semi-1.14.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

# This fix will be unnecessary for the next release.
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		semi-1.14.6-pgg-gpg.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

BUILD_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKEFLAGS=	${MAKEFLAGS.${EMACS_FLAVOR}}

EVAL_PREFIX+=	QKC_PREFIX=qkc
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

EMACS_MODULES=	base

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKEFLAGS.emacs+=
MAKEFLAGS.xemacs+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

post-build:
	@cd ${WRKSRC}; for i in mime-ui-en mime-ui-ja; do		\
		${RM} -f $${i}.info*;					\
		${CP} $${i}.texi $${i}.texi.orig;			\
		${QKC_PREFIX}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi;	\
		makeinfo --force --no-validate $${i}.texi;		\
	done

post-install:
	cd ${WRKSRC}; for f in mime-ui-*.info mime-*.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
	done

.include "options.mk"

.include "../../mk/emacs.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
