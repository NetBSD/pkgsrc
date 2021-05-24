# $NetBSD: Makefile,v 1.24 2021/05/24 19:52:45 wiz Exp $

DISTNAME=		Email-MIME-Encodings-1.315
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Email-MIME-Encodings
COMMENT=		Unified interface to MIME encoding and decoding
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.8.6,p5-MIME-Base64>=3.05}:../../converters/p5-MIME-Base64
BUILD_DEPENDS+=		p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Email/MIME/Encodings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
