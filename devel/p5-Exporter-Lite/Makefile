# $NetBSD: Makefile,v 1.22 2023/07/06 09:39:06 wiz Exp $

DISTNAME=	Exporter-Lite-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Exporter-Lite
COMMENT=	Perl 5 module providing lightweight exporting of variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Exporter/Lite/.packlist

EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
