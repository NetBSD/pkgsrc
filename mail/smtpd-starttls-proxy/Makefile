# $NetBSD: Makefile,v 1.7 2024/12/15 19:42:34 schmonz Exp $

DISTNAME=	smtpd-starttls-proxy-0.0.1.5
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://skarnet.org/software/smtpd-starttls-proxy/
COMMENT=	STARTTLS implementation for inetd-like mail servers
LICENSE=	isc

DEPENDS+=	s6-networking>=2.7.0.4:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps

.include "../../devel/skalibs/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
