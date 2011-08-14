# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:45 obache Exp $

DISTNAME=	Test-use-ok-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-use-ok/
COMMENT=	Alternative to Test::More::use_ok

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/use/ok/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
