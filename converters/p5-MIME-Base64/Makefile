# $NetBSD: Makefile,v 1.7 1998/08/20 15:16:43 tsarna Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/04 22:47:16 ache Exp
#

DISTNAME=       MIME-Base64-2.05
PKGNAME=        p5-MIME-Base64-2.05
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MIME

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/MIME-Base64/Base64.html

USE_PERL5=	yes

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
