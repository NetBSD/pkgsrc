# $NetBSD: Makefile,v 1.4 1999/11/12 16:57:57 agc Exp $

DISTNAME=		vim-5.4
PKGNAME=		vim-gtk-5.4
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
