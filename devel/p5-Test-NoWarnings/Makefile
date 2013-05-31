# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:49 wiz Exp $

DISTNAME=	Test-NoWarnings-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-NoWarnings/
COMMENT=	Make sure tests of Perl5 modules did not emit any warnings
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-Test-Tester>=0.107:../../devel/p5-Test-Tester

PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
