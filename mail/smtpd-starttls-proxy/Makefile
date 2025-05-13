# $NetBSD: Makefile,v 1.8 2025/05/13 03:51:40 schmonz Exp $

DISTNAME=		smtpd-starttls-proxy-0.0.2.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/smtpd-starttls-proxy/
COMMENT=		STARTTLS implementation for inetd-like mail servers
LICENSE=		isc

DEPENDS+=		s6-networking>=2.7.0.4:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig

.include "../../devel/skalibs/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
