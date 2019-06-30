# $NetBSD: Makefile,v 1.77 2019/06/30 20:16:59 nia Exp $

DISTNAME=	Text-CSV_XS-1.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CSV_XS
COMMENT=	Routines for composition and decomposition of comma-separated values
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/CSV_XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
