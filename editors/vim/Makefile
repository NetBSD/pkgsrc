# $NetBSD: Makefile,v 1.19 1999/08/08 09:31:18 rh Exp $

DISTNAME=		vim-5.4
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.oce.nl/pub/vim/unix/ \
			ftp://ftp.vim.org/pub/misc/editors/vim/unix/ \
			ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
			ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=		${DISTNAME}-src${EXTRACT_SUFX} \
			${DISTNAME}-rt${EXTRACT_SUFX}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.vim.org/

DEPENDS=		ncurses-4.2:../../devel/ncurses

CONFLICTS=		vim-gtk-*

GNU_CONFIGURE=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
