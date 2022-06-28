# $NetBSD: Makefile,v 1.9 2022/06/28 11:33:13 wiz Exp $

DISTNAME=	Shell-Guess-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Shell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Shell-Guess
COMMENT=	Make an educated guess about the shell in use
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unix-Process-[0-9]*:../../sysutils/p5-Unix-Process

PERL5_PACKLIST=	auto/Shell/Guess/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
