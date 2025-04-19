# $NetBSD: Makefile,v 1.6 2025/04/19 07:58:14 wiz Exp $

DISTNAME=	sshping-0.1.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=spook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spook/sshping/
COMMENT=	Measure character-echo latency and bandwidth for ssh session
LICENSE=	mit

USE_TOOLS=	pod2man

USE_LANGUAGES=	c c++

LDFLAGS.NetBSD+=	-pthread

.include "../../devel/cmake/build.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
