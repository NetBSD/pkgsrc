# $NetBSD: Makefile,v 1.20 1999/02/19 01:02:14 tv Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.10.3
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-inf.enst.fr/~demaille/a2ps/

DEPENDS=	papersize-1.0:../../print/papersize

CONFLICTS=	a2ps-[AL]*

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
