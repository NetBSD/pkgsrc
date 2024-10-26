# $NetBSD: Makefile,v 1.12 2024/10/26 19:19:28 schmonz Exp $

DISTNAME=	File-Copy-Recursive-Reduced-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Copy-Recursive-Reduced
COMMENT=	Recursive copying of files and directories
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Capture-Tiny>=0:../../devel/p5-Capture-Tiny
TOOL_DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Copy/Recursive/Reduced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
