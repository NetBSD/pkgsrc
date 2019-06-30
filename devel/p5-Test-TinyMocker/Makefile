# $NetBSD: Makefile,v 1.12 2019/06/30 20:15:57 nia Exp $

DISTNAME=	Test-TinyMocker-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-TinyMocker
COMMENT=	Very simple Perl5 tool to mock external modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/TinyMocker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
