# $NetBSD: Makefile,v 1.29 2019/08/11 13:22:58 wiz Exp $

DISTNAME=		Net-SSH-Perl-2.14
PKGNAME=		p5-${DISTNAME:C/-Perl//}
PKGREVISION=		2
CATEGORIES=		security net perl5
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/S/SC/SCHWIGON/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-SSH-Perl
COMMENT=		Perl implementations of SSH1 and SSH2 protocols
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Convert-PEM>=0.05:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-CryptX>=0.032:../../security/p5-CryptX
DEPENDS+=		p5-Digest-BubbleBabble>=0.01:../../security/p5-Digest-BubbleBabble
DEPENDS+=		p5-Math-GMP>=1.04:../../math/p5-Math-GMP
DEPENDS+=		p5-String-CRC32>=1.2:../../textproc/p5-String-CRC32
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Crypt-Curve25519>=0.05:../../security/p5-Crypt-Curve25519
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA

PERL5_PACKLIST=		auto/Net/SSH/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
