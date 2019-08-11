# $NetBSD: Makefile,v 1.14 2019/08/11 13:22:41 wiz Exp $

DISTNAME=	PDFlib-Lite-7.0.5
PKGNAME=	pdflib-lite-7.0.5
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/binaries/PDFlib/705/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pdflib.com/
COMMENT=	C library to produce PDF files

CONFLICTS+=	pdflib-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-java=no
CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-py=no
CONFIGURE_ARGS+=	--with-ruby=no
CONFIGURE_ARGS+=	--with-tcl=no

DOCDIR=		${PREFIX}/share/doc/pdflib

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC}/doc/pdflib; for file in				\
		PDFlib-Lite-license.pdf					\
		PDFlib-API-reference.pdf;				\
	do								\
		${INSTALL_DATA} $${file} ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
