# $NetBSD: Makefile,v 1.3 2001/01/04 14:18:50 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		readline-*:../../devel/readline

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

CPPFLAGS+=		-I${LOCALBASE}/include		# readline.h
LIBS+=			-ltermcap

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
