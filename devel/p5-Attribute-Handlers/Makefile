# $NetBSD: Makefile,v 1.1.1.1 2002/01/18 21:55:47 mjl Exp $

DISTNAME=	Attribute-Handlers-0.76
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ah
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/DCONWAY/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	
COMMENT=	Simpler definition of attribute handlers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Attribute/Handlers/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
