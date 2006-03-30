# $NetBSD: Makefile,v 1.23 2006/03/30 23:39:23 jlam Exp $
#
# TODO:
# * Control ${WRKSRC}/SEMI-ELS explicitly, otherwise Emacs/XEmacs founds
#   bbdb / w3 if installed.
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
DEPENDS+=	${EMACS_PKGNAME_PREFIX}flim>=1.14.2:../../devel/flim
EMACS_MODULES=	base

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=9.22:../../devel/apel
BUILD_TARGET=	elc
INSTALL_TARGET=	install
.else	# ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=	package
INSTALL_TARGET=	install-package
MAKEFLAGS+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

EVAL_PREFIX+=	QKC_PREFIX=qkc
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

.include "options.mk"

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
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};          \
	done

.include "../../mk/bsd.pkg.mk"
