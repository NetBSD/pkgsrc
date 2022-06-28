# $NetBSD: Makefile,v 1.2 2022/06/28 11:33:29 wiz Exp $

DISTNAME=	Test-Snapshot-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Snapshot
COMMENT=	Test against data stored in automatically-named file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Diff>=0:../../textproc/p5-Text-Diff

TEST_DEPENDS+=	p5-Capture-Tiny>=0:../../devel/p5-Capture-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Snapshot/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
