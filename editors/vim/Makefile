# $NetBSD: Makefile,v 1.15 1999/02/12 21:32:59 tron Exp $

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

LDFLAGS+=		"-L${LOCALBASE}/lib"
WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses

.include "../../mk/bsd.pkg.mk"
