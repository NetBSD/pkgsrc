# $NetBSD: Makefile,v 1.5 2002/11/14 23:40:46 jlam Exp $
#

DISTNAME=	dvi2tty
PKGNAME=	dvi2tty-1.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITES=	ftp://tug.ctan.org/pub/tex-archive/dviware/

MAINTAINER=	fredb@netbsd.org
COMMENT=	Program for previewing DVI files

LICENSE=	no-commercial-use

USE_BUILDLINK2=	# defined
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

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
