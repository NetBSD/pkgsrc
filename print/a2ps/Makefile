# $NetBSD: Makefile,v 1.26 2000/06/01 11:23:39 rh Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.12
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-inf.enst.fr/~demaille/a2ps/

DEPENDS+=	papersize-1.0.2:../../print/papersize
DEPENDS+=	psutils-1.17:../../print/psutils

STRIP=
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LPR=lpr
USE_PERL5=	yes
USE_GTEXINFO=	yes
USE_PKGLIBTOOL=	yes
INFO_FILES=	a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../mk/bsd.pkg.mk"
