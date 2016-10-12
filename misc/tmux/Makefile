# $NetBSD: Makefile,v 1.38 2016/10/12 10:11:23 leot Exp $

DISTNAME=	tmux-2.3
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tmux.github.io/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

GITHUB_RELEASE=	${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_TERMINFO=	yes

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*) && \
    !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=	opt:-D_XPG4_2:-D_XPG6
.endif

# https://trac.macports.org/changeset/127986
.if !empty(MACHINE_PLATFORM:MDarwin-1[0-9]*)
CPPFLAGS+=	-D__DARWIN_VERS_1050=0
.endif

# XXX: This will not needed for tmux-2.3 because a different fix
# XXX: was applied by upstream!
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE	# for reallocarray(3)

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.10
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
