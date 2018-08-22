# $NetBSD: Makefile,v 1.40 2018/08/22 09:43:06 wiz Exp $

DISTNAME=	Convert-UUlib-1.5
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-UUlib/
COMMENT=	Perl5 module interface to the uulib library
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Canary-Stability>=0:../../devel/p5-Canary-Stability

PERL5_PACKLIST=		auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
