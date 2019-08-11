# $NetBSD: Makefile,v 1.16 2019/08/11 13:22:53 wiz Exp $
#

DISTNAME=	Crypt-RC4-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-RC4
COMMENT=	Perl5 module for the "alleged" RC4 encryption algorithm

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Crypt/RC4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
