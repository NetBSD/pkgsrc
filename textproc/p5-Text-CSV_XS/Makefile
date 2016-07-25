# $NetBSD: Makefile,v 1.61 2016/07/25 23:40:45 wen Exp $
#

DISTNAME=	Text-CSV_XS-1.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CSV_XS/
COMMENT=	Routines for composition and decomposition of comma-separated values
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/CSV_XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
