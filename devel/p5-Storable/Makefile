# $NetBSD: Makefile,v 1.52 2019/08/11 13:20:20 wiz Exp $

DISTNAME=	Storable-3.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Storable
COMMENT=	Perl extension module for persistent data storage
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
