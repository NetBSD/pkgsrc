# $NetBSD: Makefile,v 1.1.1.1 2015/09/11 15:14:25 bouyer Exp $
#

DISTNAME=	Geo-Gpx-0.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~andya/Geo-Gpx-0.26/lib/Geo/Gpx.pm
COMMENT=	Geo::Gpx - Create and parse GPX files.
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/Gpx/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=	--skipdeps

DEPENDS+=	p5-DateTime-Format-ISO8601:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-HTML-Parser:../../www/p5-HTML-Parser
DEPENDS+=	p5-XML-Descent:../../textproc/p5-XML-Descent


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
