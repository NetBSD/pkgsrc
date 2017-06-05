# $NetBSD: Makefile,v 1.31 2017/06/05 14:23:10 ryoon Exp $

DISTNAME=	List-MoreUtils-0.419
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPARSEVAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-MoreUtils/
COMMENT=	Provide the stuff missing in List::Util
LICENSE=	apache-2.0

DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny

PERL5_PACKLIST=	auto/List/MoreUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
