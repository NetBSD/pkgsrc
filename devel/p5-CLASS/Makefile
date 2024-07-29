# $NetBSD: Makefile,v 1.21 2024/07/29 12:52:33 wen Exp $

DISTNAME=	CLASS-v1.1.8
PKGNAME=	p5-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JD/JDEGUEST/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CLASS
COMMENT=	Alias for __PACKAGE__
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CLASS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
