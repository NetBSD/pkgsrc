# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 11:39:31 abs Exp $

DISTNAME=	Sub-Exporter-0.974
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter/
COMMENT=	Sophisticated exporter for custom-built routines

PERL5_PACKLIST=	auto/Sub/Exporter/.packlist

DEPENDS+=    	p5-Sub-Install>=0.92:../../devel/p5-Sub-Install
DEPENDS+=    	p5-Params-Util>=0.14:../../devel/p5-Params-Util
DEPENDS+=    	p5-Data-OptList>=0.1:../../devel/p5-Data-OptList

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
