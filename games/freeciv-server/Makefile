# $NetBSD: Makefile,v 1.13 2002/09/23 10:02:49 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
COMMENT=		Freeciv game server

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

USE_BUILDLINK2=		# defined
USE_GNU_READLINE=	# uses callback interface of GNU readline
LIBS+=			-ltermcap

# Uses rl_filename_completion_function() which was introduced to the readline
# API in version 4.2.
#
BUILDLINK_DEPENDS.readline=	readline>=4.2

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
