# $NetBSD: Makefile,v 1.38 2019/08/11 13:19:42 wiz Exp $

DISTNAME=	List-MoreUtils-0.428
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPARSEVAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-MoreUtils
COMMENT=	Provide the stuff missing in List::Util
LICENSE=	apache-2.0

DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny
DEPENDS+=	p5-List-MoreUtils-XS>=0.423:../../devel/p5-List-MoreUtils-XS

PERL5_PACKLIST=	auto/List/MoreUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
