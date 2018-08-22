# $NetBSD: Makefile,v 1.15 2018/08/22 09:43:57 wiz Exp $

DISTNAME=	Exporter-Lite-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Lite/
COMMENT=	Perl 5 module providing lightweight exporting of variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Exporter/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
