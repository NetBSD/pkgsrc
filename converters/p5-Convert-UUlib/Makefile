# $NetBSD: Makefile,v 1.42 2019/08/11 13:18:12 wiz Exp $

DISTNAME=	Convert-UUlib-1.5
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	4
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-UUlib
COMMENT=	Perl5 module interface to the uulib library
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Canary-Stability>=0:../../devel/p5-Canary-Stability

PERL5_PACKLIST=		auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
