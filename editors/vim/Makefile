# $NetBSD: Makefile,v 1.16 1999/04/27 22:27:14 tron Exp $

DISTNAME=	vim-5.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.oce.nl/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/misc/editors/vim/unix/ \
		ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=	vim-5.3-src.tar.gz vim-5.3-rt.tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.vim.org/

DEPENDS=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses
LDFLAGS+=		"-L${LOCALBASE}/lib"
WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
