# $NetBSD: Makefile,v 1.5 2019/06/30 20:16:59 nia Exp $
#

DISTNAME=	Text-CSV-Simple-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CSV-Simple
COMMENT=	Simpler parsing of CSV files
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Class-Trigger-[0-9]*:../../devel/p5-Class-Trigger
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-Text-CSV_XS-[0-9]*:../../textproc/p5-Text-CSV_XS

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/CSV/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
