# $NetBSD: Makefile,v 1.1 2018/03/11 11:09:16 maya Exp $

DISTNAME=	Crypt-SMIME-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIKAGE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MI/MIKAGE/
COMMENT=	Perl5 S/MIME message signing, verification, encryption and decryption
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader>=0:../../devel/p5-XSLoader

PERL5_PACKLIST=	auto/Crypt/SMIME/.packlist

BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig-[0-9]*:../../devel/p5-ExtUtils-PkgConfig
BUILD_DEPENDS+=	p5-ExtUtils-CChecker-[0-9]*:../../devel/p5-ExtUtils-CChecker

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
