# $NetBSD: Makefile,v 1.6 2000/10/16 09:41:12 rh Exp $
#

DISTNAME=	IO-stringy-1.216
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO-stringy/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
