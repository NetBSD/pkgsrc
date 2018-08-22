# $NetBSD: Makefile,v 1.22 2018/08/22 09:44:09 wiz Exp $

DISTNAME=	IO-Tee-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=IO::Tee
COMMENT=	Multiplex output to multiple output handles
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Tee/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
