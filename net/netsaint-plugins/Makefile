# $NetBSD: Makefile,v 1.3 2001/02/17 18:19:16 wiz Exp $
#

DISTNAME=	netsaint-plugins-1.2.8-4
PKGNAME=	netsaint-plugins-1.2.8.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/
COMMENT=	basic monitoring plugins for netsaint

DEPENDS+=	netsaint-base-*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-*,openssh-*}:../../security/ssh
.endif

USE_SSL=	YES
USE_PERL5=	YES

.include "../../net/netsaint-base/Makefile.common"

.include "../../mk/bsd.pkg.mk"
