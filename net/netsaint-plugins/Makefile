# $NetBSD: Makefile,v 1.30 2008/01/18 05:08:46 tnn Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		12
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

BROKEN_IN=		pkgsrc-2006Q4

DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX:Q}
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
