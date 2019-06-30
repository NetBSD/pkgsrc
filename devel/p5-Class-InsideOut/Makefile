# $NetBSD: Makefile,v 1.16 2019/06/30 20:14:40 nia Exp $

DISTNAME=	Class-InsideOut-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-InsideOut
COMMENT=	Perl 5 safe and simple inside-out object construction kit
LICENSE=	apache-2.0

DEPENDS+=		p5-Class-ISA>=0:../../devel/p5-Class-ISA

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/InsideOut/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
