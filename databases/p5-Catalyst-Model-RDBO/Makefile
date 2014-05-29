# $NetBSD: Makefile,v 1.10 2014/05/29 23:35:25 wiz Exp $

DISTNAME=	Catalyst-Model-RDBO-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-RDBO/
COMMENT=	Rose::DB::Object model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object

PERL5_PACKLIST=	auto/Catalyst/Model/RDBO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
