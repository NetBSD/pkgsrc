# $NetBSD: Makefile,v 1.20 2021/03/04 10:42:09 nia Exp $
#

DISTNAME=	bmon-4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tgraf/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	https://github.com/tgraf/bmon
COMMENT=	Interface bandwidth monitor
LICENSE=	mit AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
