# $NetBSD: Makefile,v 1.16 2019/08/11 13:19:01 wiz Exp $

DISTNAME=	Class-ISA-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-ISA
COMMENT=	Report the search path for a class's ISA tree
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/ISA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
