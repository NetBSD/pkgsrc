# $NetBSD: Makefile,v 1.23 1999/11/25 20:20:32 tron Exp $

DISTNAME=		vim-5.5
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.vim.org/pub/editors/vim/unix/ \
			ftp://ftp.nuxi.com/pub/vim/unix/ \
			ftp://ftp.fu-berlin.de/misc/editors/vim/unix/ \
			ftp://ftp.medasys-digital-systems.fr/pub/vim/unix/ \
			ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=		${DISTNAME}-src${EXTRACT_SUFX} \
			${DISTNAME}-rt${EXTRACT_SUFX}

MAINTAINER=		pooka@iki.fi
HOMEPAGE=		http://www.vim.org/

CONFLICTS=		vim-gtk-*

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_XAW=		yes
CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
DEPENDS=		ncurses-4.2:../../devel/ncurses
.endif

.if (${XAW_TYPE} == "standard")
MAKE_ENV+=		XAW_LIB=Xaw
.else
MAKE_ENV+=		XAW_LIB=Xaw3d
.endif

.include "../../mk/bsd.pkg.mk"
