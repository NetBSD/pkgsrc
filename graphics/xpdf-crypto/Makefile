# $NetBSD: Makefile,v 1.2 1999/10/23 15:12:54 fredb Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

DISTNAME=	xpdf-0.90
PKGNAME=	xpdf-crypto-0.90
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.fefe.de/
PATCHFILES=	xpdf-0.90-fefe-diff2.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/

DEPENDS+=	t1lib-0.9.2:../../textproc/t1lib
DEPENDS+=	xpm-3.4k:../../graphics/xpm

RESTRICTED=	"Crypto; export-controlled"
MIRROR_DISTFILE= no

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-japanese

CONFLICTS=	xpdf-0.[789][a0]

MAN1=		xpdf.1 pdftops.1 pdftotext.1 pdfinfo.1 pdftopbm.1 pdfimages.1

post-install:
	@cd ${WRKSRC}/doc; \
	  for m in ${MAN1}; do \
	    nroff -Tascii -mandoc $$m > $${m%.1}.0; \
	  done; \
	  ${ECHO} ${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1; \
	  ${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1

.include "../../mk/bsd.prefs.mk"
.if ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+= --enable-a4-paper
.endif

.include "../../mk/bsd.pkg.mk"
