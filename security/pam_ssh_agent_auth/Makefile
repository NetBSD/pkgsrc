# $NetBSD: Makefile,v 1.5 2014/09/25 19:18:01 jperkin Exp $

DISTNAME=	pam_ssh_agent_auth-0.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pamsshagentauth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pamsshagentauth/
COMMENT=	PAM module which permits authentication via ssh-agent
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pod2man

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
