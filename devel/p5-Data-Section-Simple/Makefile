# $NetBSD: Makefile,v 1.17 2023/07/06 09:38:56 wiz Exp $

DISTNAME=	Data-Section-Simple-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Section-Simple
COMMENT=	Extract data from __DATA__ section of the file
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Data/Section/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
