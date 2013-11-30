# $NetBSD: Makefile,v 1.1 2013/11/30 11:30:31 wen Exp $

DISTNAME=	XML-Catalog-v1.0.1
PKGNAME=	p5-${DISTNAME:S/v1/1/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Catalog/
COMMENT=	Resolve public identifiers and remap system identifiers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XML/Catalog/.packlist

DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=0:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
