# $NetBSD: Makefile,v 1.3 2010/01/15 22:23:48 agc Exp $

DISTNAME=	pam_ssh_agent_auth-0.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pamsshagentauth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pamsshagentauth/
COMMENT=	PAM module which permits authentication via ssh-agent
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pod2man

.include "../../mk/bsd.pkg.mk"
