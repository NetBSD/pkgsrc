# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:06 jlam Exp $

DISTNAME=	Math-MatrixReal-1.3a5
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for performing operations on real matrices

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/MatrixReal/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
