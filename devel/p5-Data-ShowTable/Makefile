# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:14 veego Exp $
#

DISTNAME=		Data-ShowTable-3.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		bad@netbsd.org
COMMENT=		Perl module to print arrays of data in nicely formatted listings

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/ShowTable/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
