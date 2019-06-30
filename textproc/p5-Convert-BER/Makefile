# $NetBSD: Makefile,v 1.34 2019/06/30 20:16:48 nia Exp $
#

DISTNAME=	Convert-BER-1.32
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-BER
COMMENT=	Perl class to encode/decode objects using Basic Encoding Rules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Convert/BER/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
