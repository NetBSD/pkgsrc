# $NetBSD: Makefile,v 1.45 2021/05/24 19:49:21 wiz Exp $

DISTNAME=	Convert-UUlib-1.71
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-UUlib
COMMENT=	Perl5 module interface to the uulib library
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PERL5_PACKLIST=		auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
