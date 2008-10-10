# $NetBSD: Makefile,v 1.22 2008/10/10 11:34:50 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include	"../../security/nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
USE_TOOLS+=	bison

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
