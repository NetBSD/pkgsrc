# $NetBSD: Makefile,v 1.5 2001/05/02 15:11:18 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}

COMMENT=		Freeciv game server

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		readline>=2.2:../../devel/readline

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

CPPFLAGS+=		-I${LOCALBASE}/include		# readline.h
LIBS+=			-ltermcap			# -lreadline -ltermcap

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
