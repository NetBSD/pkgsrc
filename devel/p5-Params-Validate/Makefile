# $NetBSD: Makefile,v 1.4 2002/01/18 22:05:41 mjl Exp $

DISTNAME=	Params-Validate-0.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Validate method/function parameters

DEPENDS+=	p5-Attribute-Handlers:../../devel/p5-Attribute-Handlers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Params/Validate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
