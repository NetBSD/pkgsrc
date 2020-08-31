# $NetBSD: Makefile,v 1.10 2020/08/31 18:08:16 wiz Exp $

DISTNAME=	List-MoreUtils-XS-0.428
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-MoreUtils-XS
COMMENT=	Provide compiled List::MoreUtils functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/List/MoreUtils/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
