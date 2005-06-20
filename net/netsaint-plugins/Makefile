# $NetBSD: Makefile,v 1.22 2005/06/20 02:59:36 jlam Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		8
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
CPPFLAGS+=		-I${PGSQL_PREFIX}/include/postgresql

.include "../../net/netsaint-base/Makefile.common"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

SUBST_CLASSES+=		wrkdir
SUBST_STAGE.wrkdir=	pre-configure
SUBST_SED.wrkdir=	-e "s|@WRKDIR@|${WRKDIR:Q}|"
SUBST_FILES.wrkdir=	plugins-scripts/subst.in

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
