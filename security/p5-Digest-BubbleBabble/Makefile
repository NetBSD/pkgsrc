# $NetBSD: Makefile,v 1.30 2023/07/06 09:41:26 wiz Exp $

DISTNAME=	Digest-BubbleBabble-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-BubbleBabble
COMMENT=	Perl5 module for bubble babble fingerprints
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Digest/BubbleBabble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
