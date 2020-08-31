# $NetBSD: Makefile,v 1.45 2020/08/31 18:11:47 wiz Exp $

DISTNAME=	Filter-1.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Filter
COMMENT=	Perl5 classes representing a number of source filters
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Filter/Util/Call/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
