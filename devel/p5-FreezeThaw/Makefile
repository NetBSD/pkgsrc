# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:16 veego Exp $
#

DISTNAME=	FreezeThaw-0.41
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	packages@netbsd.org
COMMENT=	converting Perl structures to strings and back

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/FreezeThaw/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
