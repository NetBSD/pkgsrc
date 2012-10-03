# $NetBSD: Makefile,v 1.2 2012/10/03 00:02:41 asau Exp $

DISTNAME=	IRC-Utils-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IRC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IRC-Utils/
COMMENT=	Common utilities for IRC-related tasks
LICENSE=	${PERL5_LICENSE}

PREV_PKGPATH=	chat/p5-IRC-Util

PERL5_PACKLIST=	auto/IRC/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
