# $NetBSD: Makefile,v 1.7 2017/09/03 08:53:14 wiz Exp $

DISTNAME=	pam_ssh_agent_auth-0.9.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pamsshagentauth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pamsshagentauth/
COMMENT=	PAM module which permits authentication via ssh-agent
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pod2man

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
