# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# $NetBSD: Makefile,v 1.3 1998/08/20 15:17:03 tsarna Exp $
# 

DISTNAME=       xpdf-0.7a
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.aimnet.com/pub/users/derekn/xpdf/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.aimnet.com/~derekn/xpdf/

DEPENDS=	xpm-3.4k:../../graphics/xpm

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
