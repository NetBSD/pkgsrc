#
# New ports collection makefile for:	vim
# Version required:			vim-5.0
# Date Created:				19 February 1998
# Whom:					tron
#
# $NetBSD: Makefile,v 1.3 1998/02/28 22:03:20 tron Exp $

DISTNAME=	vim-5.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.oce.nl/pub/vim/unix/ \
		ftp://uiarchive.uiuc.edu/pub/packages/vim/ \
		ftp://ftp.fu-berlin.de/pub/misc/editors/vim/unix/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/

MAINTAINER=	tron@netbsd.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

MAN1=	ex.1 gview.1 gvim.1 rgview.1 rgvim.1 rview.1 view.1 vim.1 xxd.1 \
	vim-ctags.1 vim-etags.1

.include <bsd.port.mk>
