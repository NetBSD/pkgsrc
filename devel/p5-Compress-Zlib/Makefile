# $NetBSD: Makefile,v 1.5 2002/01/19 03:04:47 mjl Exp $

DISTNAME=		Compress-Zlib-1.16
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		perl5 module interface to the zlib compression library

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Zlib/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../devel/zlib/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
