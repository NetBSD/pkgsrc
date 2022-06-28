# $NetBSD: Makefile,v 1.10 2022/06/28 11:32:29 wiz Exp $

DISTNAME=	Find-Lib-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Find/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Find-Lib
COMMENT=	Helper to smartly find libs to use in the filesystem tree
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Find/Lib/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
