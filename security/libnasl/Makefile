# $NetBSD: Makefile,v 1.14 2005/04/04 09:32:45 adam Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=			${WRKDIR}/libnasl
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
