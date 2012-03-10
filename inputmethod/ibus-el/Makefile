# $NetBSD: Makefile,v 1.7 2012/03/10 10:56:13 obache Exp $
#

DISTNAME=	ibus-el-0.2.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www11.atwiki.jp/s-irie/pub/emacs/ibus/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www11.atwiki.jp/s-irie/pages/21.html
COMMENT=	IBus client for GNU Emacs
LICENSE=	gnu-gpl-v3

DEPENDS+=	ibus>=1.2:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
EMACS_VERSIONS_ACCEPTED=	emacs22 emacs23 emacs24
PYTHON_VERSIONS_INCOMPATIBLE=	24 25

REPLACE_PYTHON=	ibus-el-agent
# then execute directly
SUBST_CLASSES+=		pycmd
SUBST_STAGE.pycmd=	pre-build
SUBST_FILES.pycmd=	ibus.el
SUBST_SED.pycmd=	-e 's|"python"|nil|'

do-build:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${PKGSRC_MAKE_ENV} \
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ibus.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/ibus.el ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/ibus.elc ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/ibus-el-agent ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
