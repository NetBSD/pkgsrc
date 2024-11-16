# $NetBSD: Makefile,v 1.9 2024/11/16 12:03:16 wiz Exp $

DISTNAME=	Convert-UU-0.5201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-UU
COMMENT=	Perl5 module interface to uuencode and uudecode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Convert/UU/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
