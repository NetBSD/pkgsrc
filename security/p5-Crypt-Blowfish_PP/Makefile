# $NetBSD: Makefile,v 1.10 2019/08/11 13:22:50 wiz Exp $
#

DISTNAME=	Crypt-Blowfish_PP-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-Blowfish_PP
COMMENT=	Blowfish encryption algorithm implemented purely in Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/Blowfish_PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
