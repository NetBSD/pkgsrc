# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:56 jlam Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5wre
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provide weak references in Perl

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WeakRef/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
