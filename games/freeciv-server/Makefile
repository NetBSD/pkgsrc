# $NetBSD: Makefile,v 1.9 2001/06/11 02:05:10 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}

COMMENT=		Freeciv game server

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

USE_GNU_READLINE=	# uses callback interface of GNU readline

.include "../../devel/readline/buildlink.mk"

CONFIGURE_ENV+=		LIBS="${LIBS}"
LIBS+=			-ltermcap

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
