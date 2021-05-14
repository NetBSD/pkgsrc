# $NetBSD: Makefile,v 1.11 2021/05/14 11:52:15 nia Exp $

DISTNAME=	pam_ssh_agent_auth-0.10.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeverly/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/jbeverly/pam_ssh_agent_auth
COMMENT=	PAM module which permits authentication via ssh-agent
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pod2man

GITHUB_SUBMODULES+=	floodyberry ed25519-donna 8757bd4cd209cb032853ece0ce413f122eef212c ed25519-donna

CONFIGURE_ARGS+=	--without-openssl-header-check

INSTALLATION_DIRS+=	${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
