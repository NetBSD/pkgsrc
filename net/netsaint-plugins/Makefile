# $NetBSD: Makefile,v 1.8 2002/03/26 20:16:18 rh Exp $
#

DISTNAME=		netsaint-plugins-1.2.9-4
PKGNAME=		netsaint-plugins-1.2.9.4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://prdownloads.sourceforge.net/netsaintplug/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://netsaintplug.sourceforge.net/
COMMENT=		NetSaint plugins

DEPENDS+=		autoconf>=2.13:../../devel/autoconf
DEPENDS+=		automake>=1.4.5:../../devel/automake
DEPENDS+=		netsaint-base-[0-9]*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

USE_SSL=		YES

.include "../../net/netsaint-base/Makefile.common"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pkt nokernfs,procfs"
.endif

pre-configure:
	cd ${WRKSRC};	\
	${LOCALBASE}/bin/aclocal;	\
	${LOCALBASE}/bin/autoheader;	\
	${LOCALBASE}/bin/automake -a --foreign -i;	\
	${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
