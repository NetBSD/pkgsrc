# $NetBSD: Makefile,v 1.31 2019/06/30 20:14:41 nia Exp $

DISTNAME=	Class-ReturnValue-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-ReturnValue
COMMENT=	Perl5 module for return-value object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/ReturnValue/.packlist

DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
