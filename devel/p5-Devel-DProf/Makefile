# $NetBSD: Makefile,v 1.4 2000/08/27 21:13:43 jlam Exp $
#

DISTNAME=		DProf-19990108
PKGNAME=		p5-Devel-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@netbsd.org

CONFLICTS=		perl-5.6.0	# needs perl>5.6.0 or perl-5.00*

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/DProf/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
