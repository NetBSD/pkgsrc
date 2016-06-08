# $NetBSD: Makefile,v 1.20 2016/06/08 19:22:38 wiz Exp $

DISTNAME=	Carp-Assert-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/search?dist=Carp-Assert
COMMENT=	Executable comments like the ANSI C library assert.h
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
