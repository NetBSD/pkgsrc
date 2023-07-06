# $NetBSD: Makefile,v 1.15 2023/07/06 09:40:04 wiz Exp $

DISTNAME=	Sub-Quote-2.006008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Quote
COMMENT=	Efficient generation of subroutines via string eval
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sub/Quote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
