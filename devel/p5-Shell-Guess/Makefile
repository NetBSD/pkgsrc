# $NetBSD: Makefile,v 1.3 2018/08/22 09:44:37 wiz Exp $

DISTNAME=	Shell-Guess-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Shell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Shell-Guess/
COMMENT=	Make an educated guess about the shell in use
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unix-Process-[0-9]*:../../sysutils/p5-Unix-Process

PERL5_PACKLIST=	auto/Shell/Guess/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
