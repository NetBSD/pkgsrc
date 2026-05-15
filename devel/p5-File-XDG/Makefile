# $NetBSD: Makefile,v 1.1 2026/05/15 07:49:36 wiz Exp $

DISTNAME=	File-XDG-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/File::XDG
COMMENT=	Basic implementation of the XDG base directory specification
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Ref-Util>=0:../../devel/p5-Ref-Util
TEST_DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class

PERL5_PACKLIST=	auto/File/XDG/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
