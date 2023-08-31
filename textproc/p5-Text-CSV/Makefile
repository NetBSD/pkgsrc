# $NetBSD: Makefile,v 1.36 2023/08/31 13:22:19 wen Exp $
#

DISTNAME=	Text-CSV-2.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CSV
COMMENT=	Comma-separated values manipulator (using XS or PurePerl)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-CSV_XS>=1.51:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=		auto/Text/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
