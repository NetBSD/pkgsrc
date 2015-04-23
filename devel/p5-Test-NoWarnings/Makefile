# $NetBSD: Makefile,v 1.15 2015/04/23 06:42:58 mef Exp $

DISTNAME=	Test-NoWarnings-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-NoWarnings/
COMMENT=	Make sure tests of Perl5 modules did not emit any warnings
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
