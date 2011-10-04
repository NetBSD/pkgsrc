# $NetBSD: Makefile,v 1.31 2011/10/04 03:09:25 hiramatsu Exp $
#

DISTNAME=	semi-1.14.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/comp/emacsen/lisp/semi/semi-1.14-for-flim-1.14/

# This fix will be unnecessary for the next release.
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		semi-1.14.6-pgg-gpg.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

BUILD_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/semi \
			${EMACS_INFOPREFIX:C|^${PREFIX}/||}

BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKEFLAGS=	${MAKEFLAGS.${EMACS_FLAVOR}}

EVAL_PREFIX+=	QKC_PREFIX=qkc
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

EMACS_MODULES=	base
EMACS_BUILDLINK=# defined

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

do-install: plist
	cd ${WRKSRC};							\
	grep -v '^@' ${PLIST} | grep '/site-lisp/semi/' |		\
	while read file; do						\
		file=$$( basename $$file );				\
		${INSTALL_DATA} $$file					\
		    ${DESTDIR}${EMACS_LISPPREFIX}/semi/$$file;		\
	done

post-install:
	cd ${WRKSRC}; for f in mime-ui-*.info mime-*.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done

.include "options.mk"

.include "../../editors/emacs/modules.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
