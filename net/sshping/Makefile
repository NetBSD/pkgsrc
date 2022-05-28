# $NetBSD: Makefile,v 1.2 2022/05/28 20:46:16 leot Exp $

DISTNAME=	sshping-0.1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=spook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spook/sshping/
COMMENT=	Measure character-echo latency and bandwidth for ssh session
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS=	pod2man

USE_LANGUAGES=	c c++

.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
