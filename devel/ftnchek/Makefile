# $NetBSD: Makefile,v 1.20 2013/06/12 12:35:35 wiz Exp $

DISTNAME=	ftnchek-3.2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.dsm.fordham.edu/~ftnchek/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dsm.fordham.edu/~ftnchek/
COMMENT=	Static analyzer for Fortran programs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/libexec
CONFIGURE_ARGS+=--disable-submodel

USE_TOOLS+=	soelim

.if (${MACHINE_ARCH} == "arm")
CFLAGS+=	-O1
.endif

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/emacs/site-lisp
INSTALLATION_DIRS+=	share/doc/ftnchek share/doc/ftnchek/html

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ INSTALL LICENSE README 	\
		ftnchek.man dcl2inc.man macro-doc.txt 			\
		${DESTDIR}${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA} ${WRKSRC}/html/* \
		${DESTDIR}${PREFIX}/share/doc/ftnchek/html

.include "../../mk/bsd.pkg.mk"
