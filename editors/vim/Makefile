# $NetBSD: Makefile,v 1.21 1999/11/12 16:55:11 agc Exp $

DISTNAME=		vim-5.4
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.oce.nl/pub/vim/unix/ \
			ftp://ftp.vim.org/pub/misc/editors/vim/unix/ \
			ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
			ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=		${DISTNAME}-src${EXTRACT_SUFX} \
			${DISTNAME}-rt${EXTRACT_SUFX}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.vim.org/

CONFLICTS=		vim-gtk-*

GNU_CONFIGURE=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS=		ncurses-4.2:../../devel/ncurses
.endif

.include "../../mk/bsd.pkg.mk"
