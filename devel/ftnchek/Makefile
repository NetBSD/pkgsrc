# $NetBSD: Makefile,v 1.26 2024/02/10 10:22:15 wiz Exp $

DISTNAME=	ftnchek-3.3.1
CATEGORIES=	devel
MASTER_SITES=	https://www.dsm.fordham.edu/~ftnchek/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dsm.fordham.edu/~ftnchek/
COMMENT=	Static analyzer for Fortran programs

GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBDIR=	${PREFIX}/libexec
CONFIGURE_ARGS+=	--disable-submodel

USE_TOOLS+=	soelim

CFLAGS+=	-fPIE

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
