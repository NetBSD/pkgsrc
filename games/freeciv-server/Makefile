# $NetBSD: Makefile,v 1.11 2001/06/21 05:06:17 jlam Exp $

.include "../../games/freeciv-share/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-server-/}
COMMENT=		Freeciv game server

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# uses callback interface of GNU readline
LIBS+=			-ltermcap

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../devel/readline/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
