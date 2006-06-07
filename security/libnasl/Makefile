# $NetBSD: Makefile,v 1.19 2006/06/07 12:32:31 joerg Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
USE_TOOLS+=	bison

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
