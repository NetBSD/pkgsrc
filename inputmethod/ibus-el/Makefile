# $NetBSD: Makefile,v 1.16 2017/08/16 20:21:10 wiz Exp $
#

DISTNAME=	ibus-el-0.3.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	inputmethod
MASTER_SITES=	http://www11.atwiki.jp/s-irie/pub/emacs/ibus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www11.atwiki.jp/s-irie/pages/21.html
COMMENT=	IBus client for GNU Emacs
LICENSE=	gnu-gpl-v3

DEPENDS+=	{${PYPKGPREFIX}-ibus-python-[0-9]*,ibus>=1.2<1.5}:../../inputmethod/ibus-python
DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

USE_LANGUAGES=	# none
EMACS_VERSIONS_ACCEPTED=	emacs22 emacs23 emacs24

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
