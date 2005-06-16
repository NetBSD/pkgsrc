# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	dvi2tty
PKGNAME=	dvi2tty-1.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITES=	ftp://tug.ctan.org/pub/tex-archive/dviware/

MAINTAINER=	fredb@NetBSD.org
COMMENT=	Program for previewing DVI files

LICENSE=	no-commercial-use

MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin man/man1

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
