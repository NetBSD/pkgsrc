# $NetBSD: Makefile,v 1.16 2004/03/26 02:27:48 wiz Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql

.include "../../net/netsaint-base/Makefile.common"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
