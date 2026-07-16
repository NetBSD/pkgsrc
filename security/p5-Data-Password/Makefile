# $NetBSD: Makefile,v 1.2 2026/07/16 19:04:47 wiz Exp $

DISTNAME=	Data-Password-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::Password
COMMENT=	Perl extension for assessing password quality
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/Password/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
