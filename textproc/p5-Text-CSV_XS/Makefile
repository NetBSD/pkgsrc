# $NetBSD: Makefile,v 1.50 2014/07/06 15:26:20 schmonz Exp $
#

DISTNAME=	Text-CSV_XS-1.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tcx
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
