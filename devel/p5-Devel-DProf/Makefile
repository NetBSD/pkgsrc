# $NetBSD: Makefile,v 1.7 2001/02/26 07:23:57 jlam Exp $
#

DISTNAME=		DProf-19990108
PKGNAME=		p5-Devel-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@netbsd.org
COMMENT=		perl5 module for profiling perl programs

# Some perl packages install their own versions of this module.
# Can't simply define USE_PERL5.
DEPENDS+=		perl-{5.0*,5.6.0nb[12],base-5.[6-9]*}:../../lang/perl5-base

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/DProf/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

.if !defined(PERL5_SITEARCH)
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`; \
			${ECHO} $${installsitearch}
.endif
