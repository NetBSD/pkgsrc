# $NetBSD: Makefile,v 1.13 2019/08/11 13:18:54 wiz Exp $

DISTNAME=	CHI-0.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CHI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CHI
COMMENT=	Unified cache handling interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CHI/.packlist

DEPENDS+=	p5-Carp-Assert>=0.20:../../devel/p5-Carp-Assert
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID
DEPENDS+=	p5-Digest-JHash-[0-9]*:../../security/p5-Digest-JHash
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Hash-MoreUtils-[0-9]*:../../devel/p5-Hash-MoreUtils
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-List-MoreUtils>=0.13:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Log-Any>=0.08:../../devel/p5-Log-Any
DEPENDS+=	p5-Moo>=1.003:../../devel/p5-Moo
DEPENDS+=	p5-MooX-Types-MooseLike>=0.23:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-MooX-Types-MooseLike-Numeric-[0-9]*:../../devel/p5-MooX-Types-MooseLike-Numeric
#DEPENDS+=	{perl>=5.7.3,p5-Storable-[0-9]*}:../../devel/p5-Storable
DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Time-Duration>=1.06:../../time/p5-Time-Duration
DEPENDS+=	p5-Time-Duration-Parse>=0.03:../../time/p5-Time-Duration-Parse
#DEPENDS+=	{perl>=5.8.1,p5-Time-HiRes>=1.30}:../../time/p5-Time-HiRes
DEPENDS+=	p5-Try-Tiny>=0.05:../../devel/p5-Try-Tiny

# for make test
BUILD_DEPENDS+=	p5-Test-Class-[0-9]*:../../devel/p5-Test-Class
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
