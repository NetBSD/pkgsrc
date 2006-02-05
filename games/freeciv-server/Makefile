# $NetBSD: Makefile,v 1.21 2006/02/05 23:09:14 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
PKGREVISION=	1
COMMENT=	Freeciv game server

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

USE_GNU_READLINE=	yes
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--with-readline
LIBS+=			-ltermcap

# Uses rl_filename_completion_function() which was introduced in readline-4.2
BUILDLINK_DEPENDS.readline+=	readline>=4.2

.include "../../games/freeciv-share/Makefile.common"

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
