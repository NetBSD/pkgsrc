# $NetBSD: Makefile,v 1.1.1.1 2001/05/26 13:04:32 fredb Exp $
#

DISTNAME=	dvi2tty
PKGNAME=	dvi2tty-1.0
CATEGORIES=	converters
MASTER_SITES=	ftp://tug.ctan.org/pub/tex-archive/dviware/

MAINTAINER=	fredb@netbsd.org
COMMENT=	Program for previewing DVI files

pre-patch:
	cd ${WRKSRC};						\
	    for p in dvi2tty.patch dvi2tty-latin1.patch;	\
	    do							\
		${PATCH} < $$p;					\
	    done

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/disdvi ${WRKSRC}/dvi2tty ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
