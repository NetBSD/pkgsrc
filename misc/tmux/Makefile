# $NetBSD: Makefile,v 1.57 2021/12/29 19:18:39 rhialto Exp $

DISTNAME=	tmux-3.2a
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://tmux.github.io/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TERMINFO=	yes

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		pre-configure
SUBST_MESSAGE.sysconfdir=	Do not force sysconfdir to /etc
SUBST_FILES.sysconfdir=		configure configure.ac
SUBST_SED.sysconfdir=		-e '/Default tmux\.conf goes in \/etc/d'
SUBST_SED.sysconfdir+=		-e '/sysconfdir=\/etc/d'

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*) && \
    !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=	opt:-D_XPG4_2:-D_XPG6
.endif

# https://trac.macports.org/changeset/127986
.if !empty(MACHINE_PLATFORM:MDarwin-1[0-9].*)
CPPFLAGS+=	-D__DARWIN_VERS_1050=0
.endif

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.10
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
