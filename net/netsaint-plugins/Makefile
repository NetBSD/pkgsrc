# $NetBSD: Makefile,v 1.5 2002/03/13 17:37:32 fredb Exp $
#

DISTNAME=	netsaint-plugins-1.2.8-4
PKGNAME=	netsaint-plugins-1.2.8.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/
COMMENT=	basic monitoring plugins for netsaint

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

USE_SSL=	YES
USE_PERL5=	YES

.include "../../net/netsaint-base/Makefile.common"

.include "../../mk/bsd.pkg.mk"
