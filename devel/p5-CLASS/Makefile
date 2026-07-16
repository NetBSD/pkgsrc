# $NetBSD: Makefile,v 1.24 2026/07/16 19:01:55 wiz Exp $

DISTNAME=	CLASS-v1.1.8
PKGNAME=	p5-${DISTNAME:S/v//}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JD/JDEGUEST/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CLASS
COMMENT=	Alias for __PACKAGE__
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CLASS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
