# $NetBSD: Makefile,v 1.6 1998/06/22 13:51:33 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/04 22:47:16 ache Exp
#

DISTNAME=       MIME-Base64-2.05
PKGNAME=        p5-MIME-Base64-2.05
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MIME

MAINTAINER=	hubertf@netbsd.org

USE_PERL5=	yes

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
