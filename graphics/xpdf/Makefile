# $NetBSD: Makefile,v 1.8 1999/09/24 01:30:20 fredb Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

DISTNAME=	xpdf-0.90
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/

DEPENDS+=	t1lib-0.9.2:../../textproc/t1lib
DEPENDS+=	xpm-3.4k:../../graphics/xpm

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

MAN1=		xpdf.1 pdftops.1 pdftotext.1 pdfinfo.1 pdftopbm.1 pdfimages.1

post-install:
	@cd ${WRKSRC}/doc; \
	  for m in ${MAN1}; do \
	    nroff -Tascii -mandoc $$m > $${m%.1}.0; \
	  done; \
	  ${ECHO} ${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1; \
	  ${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"
