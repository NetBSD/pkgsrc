# $NetBSD: Makefile,v 1.11 2023/07/06 09:40:00 wiz Exp $

DISTNAME=	Shell-Config-Generate-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Shell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Shell-Config-Generate
COMMENT=	Portably generate config for any shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Shell-Guess-[0-9]*:../../devel/p5-Shell-Guess
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh

PERL5_PACKLIST=	auto/Shell/Config/Generate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
