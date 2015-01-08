# $NetBSD: Makefile,v 1.8 2015/01/08 14:11:02 wen Exp $

DISTNAME=	Class-Field-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Field/
COMMENT=	Perl 5 class field accessor generator
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Field/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
