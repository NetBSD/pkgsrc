# $NetBSD: Makefile,v 1.12 2023/07/06 09:41:23 wiz Exp $

DISTNAME=	Crypt-PWSafe3-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-PWSafe3
COMMENT=	Perl module interface to Passwordsafe v3 files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Crypt-ECB-[0-9]*:../../security/p5-Crypt-ECB
DEPENDS+=	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=	p5-Crypt-Twofish-[0-9]*:../../security/p5-Crypt-Twofish
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID

PERL5_PACKLIST=		auto/Crypt/PWSafe3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
