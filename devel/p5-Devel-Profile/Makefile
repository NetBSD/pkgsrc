# $NetBSD: Makefile,v 1.7 2005/08/06 06:19:10 jlam Exp $

DISTNAME=	Devel-Profile-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Profile/
COMMENT=	Perl5 module for profiling perl programs

PERL5_PACKLIST=	auto/Devel/Profile/.packlist

DEPENDS+=	p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
