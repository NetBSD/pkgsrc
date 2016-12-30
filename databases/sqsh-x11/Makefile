# $NetBSD: Makefile,v 1.11 2016/12/30 13:33:45 wiz Exp $

PKGNAME=	sqsh-x11-${VERSION}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Athena GUI)

CONFIGURE_ARGS+=	--with-x

.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../databases/sqsh/Makefile.common"
.include "../../mk/bsd.pkg.mk"
