# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:13 veego Exp $

DISTNAME=		Compress-Zlib-1.14
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		perl5 module interface to the zlib compression library

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Zlib/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
