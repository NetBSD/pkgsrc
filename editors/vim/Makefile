# $NetBSD: Makefile,v 1.11 1998/09/14 21:48:04 garbled Exp $

DISTNAME=	vim-5.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.oce.nl/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/misc/editors/vim/unix/ \
		ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTFILES=	vim-5.3-src.tar.gz vim-5.3-rt.tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.vim.org/

LDFLAGS+=	-Wl,-R${X11BASE}/lib
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
