# $NetBSD: Makefile,v 1.5 2018/05/06 06:46:12 wiz Exp $

DISTNAME=	Test-TempDir-Tiny-0.017
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TempDir-Tiny/
COMMENT=	Temporary directories that stick around when tests fail
LICENSE=	apache-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/TempDir/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
