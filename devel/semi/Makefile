# $NetBSD: Makefile,v 1.20 2005/09/17 16:41:23 uebayasi Exp $
#
# TODO:
# * Control ${WRKSRC}/SEMI-ELS explicitly, otherwise Emacs/XEmacs founds
#   bbdb / w3 if installed.
#

DISTNAME=	semi-1.14.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

# This fix will be unnecessary for the next release.
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		semi-1.14.6-pgg-gpg.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	${EMACS_PKGNAME_PREFIX}flim>=1.14.2:../../devel/flim
BUILD_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=9.22:../../devel/apel
BUILD_TARGET=	elc
INSTALL_TARGET=	install
.else	# ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
BUILD_TARGET=	package
INSTALL_TARGET=	install-package
MAKEFLAGS+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
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

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
