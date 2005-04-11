# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:13 tv Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=			${WRKDIR}/libnasl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
