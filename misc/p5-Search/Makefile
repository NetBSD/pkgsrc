# $NetBSD: Makefile,v 1.5 1998/06/22 12:52:33 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/06/24 18:43:31 jfitz Exp
#

DISTNAME=		Search-0.2
PKGNAME=		p5-Search-0.2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search

MAINTAINER=		packages@netbsd.org

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
