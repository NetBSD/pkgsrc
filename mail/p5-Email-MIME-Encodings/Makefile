# $NetBSD: Makefile,v 1.22 2019/08/11 13:21:32 wiz Exp $

DISTNAME=		Email-MIME-Encodings-1.315
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
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
