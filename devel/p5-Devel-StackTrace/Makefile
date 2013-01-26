# $NetBSD: Makefile,v 1.31 2013/01/26 20:12:31 rhaen Exp $

DISTNAME=	Devel-StackTrace-1.30
PKGNAME=	p5-${DISTNAME}00
SVR4_PKGNAME=	p5dst
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=	Perl5 module for stack trace and stack trace frame objects
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
