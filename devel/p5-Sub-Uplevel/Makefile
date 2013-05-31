# $NetBSD: Makefile,v 1.20 2013/05/31 12:40:45 wiz Exp $

DISTNAME=	Sub-Uplevel-0.24
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Uplevel/
COMMENT=	Apparently run a function in a higher stack frame
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sub/Uplevel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
