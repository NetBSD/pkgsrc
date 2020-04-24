# $NetBSD: Makefile,v 1.9 2020/04/24 11:41:37 nia Exp $

DISTNAME=	pam_ssh_agent_auth-0.9.2
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pamsshagentauth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pamsshagentauth/
COMMENT=	PAM module which permits authentication via ssh-agent
LICENSE=	modified-bsd

BROKEN=		"Fails to build with OpenSSL 1.1"

GNU_CONFIGURE=	yes
USE_TOOLS+=	pod2man

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
