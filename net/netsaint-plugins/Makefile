# $NetBSD: Makefile,v 1.11 2002/06/17 11:10:22 wiz Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4.5:../../devel/automake

DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

.include "../../net/netsaint-base/Makefile.common"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

pre-configure:
	cd ${WRKSRC};	\
	${LOCALBASE}/bin/aclocal;	\
	${LOCALBASE}/bin/autoheader;	\
	${LOCALBASE}/bin/automake -a --foreign -i;	\
	${LOCALBASE}/bin/autoconf

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
