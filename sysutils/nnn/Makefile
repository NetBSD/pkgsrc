# $NetBSD: Makefile,v 1.19 2020/06/02 11:07:41 sjmulder Exp $

DISTNAME=	nnn-3.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/nnn/
COMMENT=	Optimized, feature-packed terminal file manager
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake pkg-config
USE_CURSES=	wide set_escdelay

INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

.include "../../mk/bsd.prefs.mk"

# NetBSD:
#   Prevent pulling in builtin termcap which conflicts with ncurses'
#   implementation, causing a crash at startup. See:
#   https://github.com/jarun/nnn/issues/445
#
# Illumos:
#   -lreadline links to system curses, causing conflicts with ncurses
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
READLINE_DEFAULT=	readline
.endif

# clock_gettime() on older glibc (eg RHEL 6). See:
# https://github.com/jarun/nnn/issues/453
MAKE_ENV.Linux+=	LDLIBS=-lrt

CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../mk/compiler.mk"

# nnn uses -std=c11 for `restrict` but c99 has it too, so use that on
# old GCC versions that don't support c11.
# https://github.com/jarun/nnn/issues/605
.if !empty(CC_VERSION:Mgcc-[123].*) || \
    !empty(CC_VERSION:Mgcc-4.[0123456].*)
SUBST_CLASSES+=		c11
SUBST_MESSAGE.c11=	Use c99 on old GCC instead of c11
SUBST_STAGE.c11=	pre-configure
SUBST_FILES.c11=	Makefile
SUBST_SED.c11=		-e 's/-std=c11/-std=c99/'
.endif

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	CFLAGS_OPTIMIZATION=
MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.curses:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.curses:Q}

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/misc/auto-completion/bash/nnn-completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/nnn
	${INSTALL_DATA} \
		${WRKSRC}/misc/auto-completion/fish/nnn.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/
	${INSTALL_DATA} \
		${WRKSRC}/misc/auto-completion/zsh/_nnn \
		${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "options.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
