# $NetBSD: Makefile,v 1.12 2020/08/31 18:06:42 wiz Exp $

DISTNAME=	IRC-Utils-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IRC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IRC-Utils
COMMENT=	Common utilities for IRC-related tasks
LICENSE=	${PERL5_LICENSE}

PREV_PKGPATH=	chat/p5-IRC-Util

PERL5_PACKLIST=	auto/IRC/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
