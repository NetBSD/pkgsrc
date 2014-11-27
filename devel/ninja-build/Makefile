# $NetBSD: Makefile,v 1.3 2014/11/27 13:38:15 joerg Exp $

NINJAVER=	1.5.1
DISTNAME=	ninja-${NINJAVER}
PKGNAME=	ninja-build-${NINJAVER}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/martine/ninja/archive/v${NINJAVER}.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://martine.github.io/ninja/
COMMENT=	Ninja is a small build system with a focus on speed
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix PREFIX
SUBST_FILES.prefix=	bootstrap.py
SUBST_VARS.prefix=	PREFIX

INSTALLATION_DIRS=	bin share/doc/ninja share/ninja

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./bootstrap.py --verbose

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/manual.asciidoc \
		${DESTDIR}${PREFIX}/share/doc/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/ninja-mode.el \
		${DESTDIR}${PREFIX}/share/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/ninja.vim \
		${DESTDIR}${PREFIX}/share/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/bash-completion \
		${DESTDIR}${PREFIX}/share/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/zsh-completion \
		${DESTDIR}${PREFIX}/share/ninja

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
