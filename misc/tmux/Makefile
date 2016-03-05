# $NetBSD: Makefile,v 1.34 2016/03/05 11:28:58 jperkin Exp $

DISTNAME=	tmux-2.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux/}
GITHUB_PROJECT=	tmux
GITHUB_TAG=	2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tmux.github.io/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TERMINFO=	yes

USE_TOOLS+=	automake pkg-config

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*) && \
    !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=	opt:-D_XPG4_2:-D_XPG6
.endif

# https://trac.macports.org/changeset/127986
.if !empty(MACHINE_PLATFORM:MDarwin-1[0-9]*)
CPPFLAGS+=	-D__DARWIN_VERS_1050=0
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	mkdir -p etc; \
	aclocal; \
	automake --add-missing --force-missing --copy --foreign; autoreconf

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.10
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
