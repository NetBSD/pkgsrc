# $NetBSD: Makefile,v 1.2 2001/09/08 15:54:01 pooka Exp $
#

DISTNAME=		vim-6.0au
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.vim.org/pub/vim/unreleased/unix/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pooka@netbsd.org
HOMEPAGE=		http://www.vim.org/
COMMENT=		Vi IMproved development version (vi clone)

GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/vim60au

CONFLICTS=		vim-xaw-* vim-gtk-* vim-share-* vim-5*

CONFIGURE_ARGS+=	--enable-gui=no --without-x

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
