# New ports collection makefile for:	xpdf
# Version required:     0.7a
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# $NetBSD: Makefile,v 1.1 1998/07/25 01:46:56 tsarna Exp $

DISTNAME=       xpdf-0.7a
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.aimnet.com/pub/users/derekn/xpdf/

MAINTAINER=	tsarna@netbsd.org

LIB_DEPENDS=	Xpm.4.:../xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gzip
#USE_X11=	yes

MAN1=		xpdf.1 pdftops.1 pdftotext.1

post-build:
	@(cd ${WRKSRC}; for m in ${MAN1} ; \
	do nroff -man $$m > $${m%.1}.0; done);

post-install:
	@(cd ${WRKSRC}; ${INSTALL_MAN} ${MAN1:S/.1/.0/} ${PREFIX}/man/cat1)

.include "../../mk/bsd.pkg.mk"
