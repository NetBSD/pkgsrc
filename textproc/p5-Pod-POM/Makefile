# $NetBSD: Makefile,v 1.31 2015/06/12 10:51:26 wiz Exp $

DISTNAME=	Pod-POM-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM/
COMMENT=	P5 module to format POD into an object format, hence POM
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
