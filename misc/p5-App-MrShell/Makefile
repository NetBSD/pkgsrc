# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:13 ryoon Exp $

DISTNAME=	App-MrShell-2.0207
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-MrShell/
COMMENT=	Mr. Shell runs a command on multiple hosts
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/App/MrShell/.packlist

DEPENDS+=	p5-Config-Tiny-[0-9]*:../../devel/p5-Config-Tiny
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
