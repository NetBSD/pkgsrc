# $NetBSD: Makefile,v 1.21 2017/04/26 13:57:49 mef Exp $
#

DISTNAME=	Text-CSV-1.94
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CSV/
COMMENT=	Comma-separated values manipulator (using XS or PurePerl)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-CSV_XS>=0.99:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=		auto/Text/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
