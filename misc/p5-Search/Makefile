# $NetBSD: Makefile,v 1.7 2000/08/27 07:11:16 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/06/24 18:43:31 jfitz Exp
#

DISTNAME=		Search-0.2
PKGNAME=		p5-Search-0.2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=		packages@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Search/Text/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
