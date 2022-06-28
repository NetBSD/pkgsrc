# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:33 wiz Exp $

DISTNAME=		Tie-CPHash-2.000
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Tie-CPHash/
COMMENT=		Case preserving but case insensitive hash table
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Tie/CPHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
