# $NetBSD: Makefile,v 1.14 2023/07/06 09:40:19 wiz Exp $

DISTNAME=	Test-TempDir-Tiny-0.018
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-TempDir-Tiny
COMMENT=	Temporary directories that stick around when tests fail
LICENSE=	apache-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/TempDir/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
