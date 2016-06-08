# $NetBSD: Makefile,v 1.9 2016/06/08 19:22:35 wiz Exp $

DISTNAME=	AutoXS-Header-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AutoXS-Header/
COMMENT=	Perl 5 module container for the AutoXS header files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AutoXS/Header/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
