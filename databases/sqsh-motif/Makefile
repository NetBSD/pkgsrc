# $NetBSD: Makefile,v 1.11 2016/12/30 13:33:45 wiz Exp $

PKGNAME=	sqsh-motif-${VERSION}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Motif GUI)

CONFIGURE_ARGS+=	--with-motif=${MOTIFBASE:Q}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../databases/sqsh/Makefile.common"
.include "../../mk/bsd.pkg.mk"
