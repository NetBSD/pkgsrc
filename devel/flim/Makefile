# $NetBSD: Makefile,v 1.33 2011/10/04 03:07:53 hiramatsu Exp $

DISTNAME=	flim-1.14.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/comp/emacsen/lisp/flim/flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/FLIM/
COMMENT=	Emacs lisp library for message representation/encoding
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

BUILD_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/flim \
			${EMACS_INFOPREFIX:C|^${PREFIX}/||}

BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKEFLAGS=	${MAKEFLAGS.${EMACS_FLAVOR}}

EVAL_PREFIX+=	QKC_PREFIX=qkc
USE_TOOLS+=	makeinfo
INFO_FILES=	yes
TEXINFO_REQD=	4.5

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKEFLAGS.emacs+=	EMACS=${EMACS_BIN}
MAKEFLAGS.xemacs+=	XEMACS=${EMACS_BIN} \
			PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

EMACS_MODULES=	base
EMACS_BUILDLINK=# defined

post-build:
	@cd ${WRKSRC}; for i in mime-en mime-ja; do			\
		${RM} -f $${i}.info*;					\
		${CP} $${i}.texi $${i}.texi.orig;			\
		${QKC_PREFIX}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi;	\
		makeinfo --force --no-validate $${i}.texi;		\
	done

do-install: plist
	cd ${WRKSRC};							\
	grep -v '^@' ${PLIST} | grep '/site-lisp/flim/' |		\
	while read file; do						\
		file=$$( basename $$file );				\
		${INSTALL_DATA} $$file					\
		    ${DESTDIR}${EMACS_LISPPREFIX}/flim/$$file;		\
	done

post-install:
	cd ${WRKSRC}; for f in mime-*.info mime-*.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done

.include "../../editors/emacs/modules.mk"

BUILDLINK_API_DEPENDS.apel+=	apel>=10.7
.include "../../devel/apel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
