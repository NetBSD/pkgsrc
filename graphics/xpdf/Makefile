# $NetBSD: Makefile,v 1.6 1999/02/20 22:48:32 hubertf Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

DISTNAME=	xpdf-0.80
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/

DEPENDS=	xpm-3.4k:../../graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"
CONFIGURE_ARGS=	--with-gzip
USE_X11BASE=	yes

MAN1=		xpdf.1 pdftops.1 pdftotext.1 pdfinfo.1 pdftopbm.1 pdfimages.1

post-install:
	@(cd ${WRKSRC}/doc; for m in ${MAN1}; \
	do nroff -man $$m > $${m%.1}.0; done; \
	${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1; \
	${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1)

.include "../../mk/bsd.pkg.mk"
