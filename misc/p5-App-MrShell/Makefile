# $NetBSD: Makefile,v 1.2 2009/08/19 19:55:01 sno Exp $

DISTNAME=	App-MrShell-2.0205
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-MrShell/
COMMENT=	Mr. Shell runs a command on multiple hosts
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/App/MrShell/.packlist

DEPENDS+=	p5-Config-Tiny-[0-9]*:../../devel/p5-Config-Tiny
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
