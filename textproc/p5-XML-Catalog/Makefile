# $NetBSD: Makefile,v 1.8 2019/06/30 20:17:06 nia Exp $

DISTNAME=	XML-Catalog-1.03
PKGNAME=	p5-${DISTNAME:S/03/0.3/}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JF/JFEARN/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Catalog
COMMENT=	Resolve public identifiers and remap system identifiers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XML/Catalog/.packlist

DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=0:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
