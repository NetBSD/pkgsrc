# $NetBSD: Makefile,v 1.1 2024/04/07 19:02:45 ryoon Exp $

DISTNAME=	flycheck-33.0
PKGNAME=	${DISTNAME:S/flycheck-/flycheck-mode-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=flycheck/}
GITHUB_PROJECT=	flycheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.flycheck.org/
COMMENT=	On the fly syntax checking for GNU Emacs
LICENSE=	gnu-gpl-v3

DEPENDS+=	dash-el-[0-9]*:../../devel/dash-el

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"

EL_FILES+=	flycheck-ert flycheck

do-build:
.for f in ${EL_FILES}
	cd ${WRKSRC} && \
	${EMACS_BIN} --no-init-file --no-site-file -L . -batch \
		-f batch-byte-compile ${WRKSRC}/${f}.el
.endfor

do-install:
.for f in ${EL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.el ${WRKSRC}/${f}.elc \
		${DESTDIR}${EMACS_LISPPREFIX}
.endfor

.include "../../mk/bsd.pkg.mk"
