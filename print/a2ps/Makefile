# $NetBSD: Makefile,v 1.22 1999/06/16 17:28:24 cgd Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.10.3
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-inf.enst.fr/~demaille/a2ps/

DEPENDS=	papersize-1.0.1:../../print/papersize

STRIP=
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LPR=lpr
USE_PERL5=	yes
USE_GTEXINFO=	yes
USE_LIBTOOL=	yes
INFO_FILES=	a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../mk/bsd.pkg.mk"
