# $NetBSD: Makefile,v 1.6 2001/05/22 06:05:25 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}

COMMENT=		Freeciv game server

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

USE_GNU_READLINE=	# uses callback interface of GNU readline

.include "../../devel/readline/Makefile.readline"

CPPFLAGS+=		-I${WRKINCDIR}
LDFLAGS+=		-L${WRKLIBDIR}
LIBS+=			-ltermcap

pre-configure: link-readline-headers link-readline-libs

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
