# $NetBSD: Makefile,v 1.2 2021/05/24 19:51:45 wiz Exp $

DISTNAME=		Test-Lib-0.002
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Warn
COMMENT=		Use libraries from a t/lib directory
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Lib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
