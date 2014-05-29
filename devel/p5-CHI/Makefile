# $NetBSD: Makefile,v 1.2 2014/05/29 23:35:40 wiz Exp $

DISTNAME=	CHI-0.58
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CHI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CHI/
COMMENT=	Unified cache handling interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CHI/.packlist

DEPENDS+=	p5-Carp-Assert>=0.20:../../devel/p5-Carp-Assert
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID
DEPENDS+=	p5-Digest-JHash-[0-9]*:../../security/p5-Digest-JHash
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Hash-MoreUtils-[0-9]*:../../devel/p5-Hash-MoreUtils
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-List-MoreUtils>=0.13:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Log-Any>=0.08:../../devel/p5-Log-Any
DEPENDS+=	p5-Moo>=1.003:../../devel/p5-Moo
DEPENDS+=	p5-MooX-Types-MooseLike>=0.23:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-MooX-Types-MooseLike-Numeric-[0-9]*:../../devel/p5-MooX-Types-MooseLike-Numeric
DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Time-Duration>=1.06:../../time/p5-Time-Duration
DEPENDS+=	p5-Time-Duration-Parse>=0.03:../../time/p5-Time-Duration-Parse
DEPENDS+=	p5-Time-HiRes>=1.30:../../time/p5-Time-HiRes
DEPENDS+=	p5-Try-Tiny>=0.05:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
