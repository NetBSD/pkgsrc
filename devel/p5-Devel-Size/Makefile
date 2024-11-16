# $NetBSD: Makefile,v 1.26 2024/11/16 12:04:07 wiz Exp $

DISTNAME=	Devel-Size-0.84
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Size
COMMENT=	Perl 5 module for finding the memory usage of variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Devel/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
