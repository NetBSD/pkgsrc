# $NetBSD: Makefile,v 1.12 2004/11/02 00:05:23 adrianp Exp $

DISTNAME=	libnasl-${VERS}

.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
