# $NetBSD: Makefile,v 1.9 2023/07/06 09:39:01 wiz Exp $

DISTNAME=	Devel-Leak-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SR/SREZIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Leak
COMMENT=	Perl module to look for objects that are not reclaimed

PERL5_PACKLIST=		auto/Devel/Leak/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
