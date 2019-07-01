# $NetBSD: Makefile,v 1.6 2019/07/01 21:35:46 nia Exp $
#

DISTNAME=	Geo-Gpx-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/ANDYA/Geo-Gpx-0.26/lib/Geo/Gpx.pm
COMMENT=	Geo::Gpx - Create and parse GPX files.
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/Gpx/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=	--skipdeps

DEPENDS+=	p5-DateTime-Format-ISO8601>=0.0800:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-HTML-Parser>=3.71:../../www/p5-HTML-Parser
DEPENDS+=	p5-XML-Descent>=1.04:../../textproc/p5-XML-Descent


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
