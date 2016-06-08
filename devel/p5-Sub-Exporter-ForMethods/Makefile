# $NetBSD: Makefile,v 1.9 2016/06/08 19:23:31 wiz Exp $

DISTNAME=	Sub-Exporter-ForMethods-0.100052
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-ForMethods/
COMMENT=	Perl 5 helper routines for using Sub::Exporter to build methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0.978:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/ForMethods/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
