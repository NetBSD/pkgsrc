# $NetBSD: Makefile,v 1.22 2024/05/11 18:58:09 adam Exp $

DISTNAME=	ninja-1.12.1
PKGNAME=	${DISTNAME:S/ninja/ninja-build/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ninja-build/}
GITHUB_PROJECT=	ninja
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ninja-build.org/
COMMENT=	Small build system with a focus on speed
LICENSE=	apache-2.0

TOOL_DEPENDS+=	re2c>=0.11.3:../../devel/re2c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
#
# Under MacOS X the LD_LIBRARY_PATH variable is unset by the build system
# running executables under /bin (namely /bin/sh).  This is part of MacOS X
# System Integrity Protection.
#
# Because many (most?) users of ninja/meson seem to need hacks involving
# LD_LIBRARY_PATH, use a non-SIP-triggering shell under MacOS X.
#
# macOS bootstraps are transitioning to mksh as the system shell, once that
# has been in place for a while we can remove the pdksh support, and ideally
# just replace this whole section with -DNINJA_SHELL=${TOOLS_PLATFORM.sh}
#
.  if ${TOOLS_PLATFORM.sh:M?*/bin/mksh}
DEPENDS+=	mksh-[0-9]*:../../shells/mksh
CFLAGS+=	-DNINJA_SHELL=${PREFIX}/bin/mksh
.  else
DEPENDS+=	pdksh-[0-9]*:../../shells/pdksh
CFLAGS+=	-DNINJA_SHELL=${PREFIX}/bin/pdksh
.  endif
.else
CFLAGS+=	-DNINJA_SHELL=/bin/sh
.endif

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin share/doc/ninja share/ninja

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./configure.py --bootstrap

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
