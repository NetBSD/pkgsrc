# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:23 agc Exp $

DISTNAME=	vim-5.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.oce.nl/pub/vim/unix/ \
		ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
		ftp://ftp.fu-berlin.de/pub/misc/editors/vim/unix/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/

MAINTAINER=	tron@netbsd.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

MAN1=	ex.1 gview.1 gvim.1 rgview.1 rgvim.1 rview.1 rvim.1 view.1 vim.1 \
	xxd.1 vim-ctags.1 vim-etags.1

.include "../../mk/bsd.pkg.mk"
