# $NetBSD: Makefile,v 1.4 2019/08/11 13:18:12 wiz Exp $

DISTNAME=	Convert-UU-0.5201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-UU
COMMENT=	Perl5 module interface to uuencode and uudecode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Convert/UU/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
