# $NetBSD: Makefile,v 1.2 2000/08/12 06:34:36 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		readline-*:../../devel/readline

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ENV+=		LIBS="${LIBS}"

CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h, readline.h
LIBS+=			-ltermcap

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
