# $NetBSD: Makefile,v 1.27 2000/06/21 07:07:40 jlam Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=		a2ps-4.12
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/

DEPENDS+=		papersize-1.0.2:../../print/papersize
DEPENDS+=		psutils-1.17:../../print/psutils

STRIP=			# empty
USE_PERL5=		# defined
USE_GTEXINFO=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/auxdir/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		LPR=lpr

INFO_FILES=		a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../mk/bsd.pkg.mk"
