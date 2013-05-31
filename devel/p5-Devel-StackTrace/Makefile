# $NetBSD: Makefile,v 1.32 2013/05/31 12:40:16 wiz Exp $

DISTNAME=	Devel-StackTrace-1.30
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
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
