# $NetBSD: Makefile,v 1.5 1999/11/22 18:57:43 tron Exp $

DISTNAME=		vim-5.5
PKGNAME=		vim-gtk-5.5
WRKSRC=			${WRKDIR}/${DISTNAME}/src
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses-4.2:../../devel/ncurses
CONFIGURE_ARGS+=	--with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
.endif

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

CONFLICTS=		vim-*

GNU_CONFIGURE=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=gtk

.include "../../mk/bsd.pkg.mk"
