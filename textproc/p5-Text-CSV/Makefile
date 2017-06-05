# $NetBSD: Makefile,v 1.22 2017/06/05 14:24:48 ryoon Exp $
#

DISTNAME=	Text-CSV-1.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
