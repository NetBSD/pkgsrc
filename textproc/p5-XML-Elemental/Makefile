# $NetBSD: Makefile,v 1.21 2023/07/06 09:42:00 wiz Exp $

DISTNAME=	XML-Elemental-2.11
PKGNAME=	p5-${DISTNAME:S/11/1.1/}
PKGREVISION=	14
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Elemental
COMMENT=	Simplistic and perlish handling of XML data
LICENSE=	artistic

DEPENDS+=	p5-XML-SAX>=0:../../textproc/p5-XML-SAX
TOOL_DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken

PERL5_PACKLIST=	auto/XML/Elemental/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
