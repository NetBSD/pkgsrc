# $NetBSD: Makefile,v 1.21 2019/06/30 20:14:48 nia Exp $

DISTNAME=	Data-Dump-Streamer-2.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Dump-Streamer
COMMENT=	Perl 5 module to serialize a data structure as Perl
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-PadWalker>=0.99:../../devel/p5-PadWalker
DEPENDS+=	p5-B-Utils-[0-9]*:../../devel/p5-B-Utils

MAKE_PARAMS+=		DDS
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Data/Dump/Streamer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
