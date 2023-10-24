# $NetBSD: Makefile,v 1.4 2023/10/24 22:10:34 wiz Exp $

DISTNAME=	sshping-0.1.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=spook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spook/sshping/
COMMENT=	Measure character-echo latency and bandwidth for ssh session
LICENSE=	mit

USE_TOOLS=	pod2man

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
