# $NetBSD: Makefile,v 1.16 2021/05/24 19:51:25 wiz Exp $

DISTNAME=	PerlIO-utf8_strict-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide fast and correct UTF-8 I/O
HOMEPAGE=	https://metacpan.org/release/PerlIO-utf8_strict
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=	c

# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/PerlIO/utf8_strict/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
