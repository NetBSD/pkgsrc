# $NetBSD: Makefile,v 1.2 2007/10/14 01:42:27 heinz Exp $

DISTNAME=	radiusclient-ng-0.5.5.1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/radiusclient-ng/ \
		http://download2.berlios.de/radiusclient-ng/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Client library and basic utilities for Radius authenticated login
HOMEPAGE=	http://developer.berlios.de/projects/radiusclient-ng/

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKG_SYSCONFSUBDIR=	radiusclient-ng
EGDIR=			${PREFIX}/share/examples/radiusclient-ng

CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFBASEDIR:Q}

EGFILES= issue port-id-map radiusclient.conf  dictionary dictionary.ascend \
	dictionary.compat dictionary.merit  dictionary.sip
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
