# $NetBSD: Makefile,v 1.16 2004/04/22 03:54:17 snj Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	Freeciv game server

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

USE_GNU_READLINE=	# uses callback interface of GNU readline
LIBS+=			-ltermcap

CONFIGURE_ARGS+=	--enable-client=no --disable-make-data
CONFIGURE_ARGS+=	--with-readline

# Uses rl_filename_completion_function() which was introduced in readline-4.2
BUILDLINK_DEPENDS.readline=	readline>=4.2

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
