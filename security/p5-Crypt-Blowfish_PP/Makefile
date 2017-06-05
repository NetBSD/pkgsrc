# $NetBSD: Makefile,v 1.6 2017/06/05 14:24:28 ryoon Exp $
#

DISTNAME=	Crypt-Blowfish_PP-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-Blowfish_PP/
COMMENT=	Blowfish encryption algorithm implemented purely in Perl
LICENSE=	${PERL5_LICENSE}

CRYPTO=		YES
PERL5_PACKLIST=		auto/Crypt/Blowfish_PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
