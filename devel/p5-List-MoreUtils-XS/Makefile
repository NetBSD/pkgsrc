# $NetBSD: Makefile,v 1.15 2024/11/16 12:04:29 wiz Exp $

DISTNAME=	List-MoreUtils-XS-0.430
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-MoreUtils-XS
COMMENT=	Provide compiled List::MoreUtils functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/List/MoreUtils/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
