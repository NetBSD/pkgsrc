# $NetBSD: Makefile,v 1.12 2023/07/06 09:38:57 wiz Exp $

DISTNAME=	Data-Stag-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Stag
COMMENT=	Structured Tags datastructures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-MLDBM-[0-9]*:../../databases/p5-MLDBM
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT

PERL5_PACKLIST=	auto/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
