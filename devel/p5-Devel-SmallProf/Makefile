# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:05 jlam Exp $
#

DISTNAME=		Devel-SmallProf-0.5
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@netbsd.org

DEPENDS=		p5-Time-HiRes-01.19:../../devel/p5-Time-HiRes

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/SmallProf/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
