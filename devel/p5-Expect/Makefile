# $NetBSD: Makefile,v 1.17 2004/02/06 08:38:59 grant Exp $

DISTNAME=	Expect-1.15
PKGNAME=	p5-Expect-1.15
SVR4_PKGNAME=	p5exp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl version of the TCL "expect" tool

DEPENDS+=	p5-IO-stty-[0-9]*:../../devel/p5-IO-Stty
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Expect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
