# $NetBSD: Makefile,v 1.12 2002/10/02 19:58:01 wiz Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

.include "../../net/netsaint-base/Makefile.common"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
