# $NetBSD: Makefile,v 1.31 2025/07/04 08:45:18 wiz Exp $

DISTNAME=	Carp-Assert-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/search?q=dist%3ACarp-Assert
COMMENT=	Executable comments like the ANSI C library assert.h
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
