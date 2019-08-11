# $NetBSD: Makefile,v 1.22 2019/08/11 13:19:04 wiz Exp $

DISTNAME=	Class-XSAccessor-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-XSAccessor
COMMENT=	Perl 5 module to generate fast XS accessors
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/XSAccessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
