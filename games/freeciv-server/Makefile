# $NetBSD: Makefile,v 1.15 2004/03/05 12:08:51 adam Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	Freeciv game server

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

USE_BUILDLINK2=		# defined
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

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
