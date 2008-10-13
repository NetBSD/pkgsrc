# $NetBSD: Makefile,v 1.23 2008/10/13 22:32:54 bad Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

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
