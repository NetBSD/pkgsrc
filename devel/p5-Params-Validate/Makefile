# $NetBSD: Makefile,v 1.7 2002/04/27 19:22:40 shell Exp $

DISTNAME=	Params-Validate-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Validate method/function parameters

DEPENDS+=	p5-Attribute-Handlers>=0.76:../../devel/p5-Attribute-Handlers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Params/Validate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
