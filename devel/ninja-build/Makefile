# $NetBSD: Makefile,v 1.28 2026/01/27 12:59:15 mef Exp $

DISTNAME=	ninja-1.13.2
PKGNAME=	${DISTNAME:S/ninja/ninja-build/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ninja-build/}
GITHUB_PROJECT=	ninja
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ninja-build.org/
COMMENT=	Small build system with a focus on speed
LICENSE=	apache-2.0

# avoid conflict with devel/py-ninja
DIST_SUBDIR=	ninja-build

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

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/ninja
INSTALLATION_DIRS+=	share/ninja
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./configure.py --bootstrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/manual.asciidoc \
		${DESTDIR}${PREFIX}/share/doc/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/ninja.vim \
		${DESTDIR}${PREFIX}/share/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/bash-completion \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/ninja
	${INSTALL_DATA} ${WRKSRC}/misc/zsh-completion \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_ninja

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
