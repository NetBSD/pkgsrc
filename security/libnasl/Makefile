# $NetBSD: Makefile,v 1.20 2008/01/18 05:09:38 tnn Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}
PKGREVISION=	1

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
USE_TOOLS+=	bison

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
