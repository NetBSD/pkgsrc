# $NetBSD: Makefile,v 1.18 2006/04/25 12:45:57 salo Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
