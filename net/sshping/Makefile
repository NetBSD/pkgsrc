# $NetBSD: Makefile,v 1.7.8.1 2026/08/05 14:31:59 maya Exp $

DISTNAME=	sshping-0.1.4
PKGREVISION=	3
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

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
