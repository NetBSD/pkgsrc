# $NetBSD: Makefile,v 1.36 2002/07/06 13:29:09 tron Exp $

DISTNAME=		a2ps-4.13b
PKGNAME=		a2ps-4.13.0.2
WRKSRC=			${WRKDIR}/a2ps-4.13
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/} \
			ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer

DEPENDS+=		papersize>=1.0.2:../../print/papersize
DEPENDS+=		psutils-1.17:../../print/psutils

STRIP=			# empty
USE_PERL5=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/auxdir/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--with-medium="${PAPERSIZE}"
AUTOMAKE_OVERRIDE=	NO

INFO_FILES=		a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
