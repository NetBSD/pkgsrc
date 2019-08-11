# $NetBSD: Makefile,v 1.24 2019/08/11 13:18:57 wiz Exp $

DISTNAME=	Carp-Assert-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/search?q=dist%3ACarp-Assert
COMMENT=	Executable comments like the ANSI C library assert.h
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
