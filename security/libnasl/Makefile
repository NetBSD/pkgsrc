# $NetBSD: Makefile,v 1.24 2010/01/17 12:02:41 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include	"../../security/nessus/Makefile.common"

DISTNAME=	libnasl-${VERS}
PKGREVISION=	2

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
USE_TOOLS+=	bison

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
