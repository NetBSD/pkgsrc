# $NetBSD: Makefile,v 1.14 1999/02/12 21:09:28 tron Exp $

DISTNAME=	vim-5.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.oce.nl/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/misc/editors/vim/unix/ \
		ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=	vim-5.3-src.tar.gz vim-5.3-rt.tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.vim.org/

LDFLAGS+=		"-L${LOCALBASE}/lib"
WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \

.include "../../mk/bsd.pkg.mk"
