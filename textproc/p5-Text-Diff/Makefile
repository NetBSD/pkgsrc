# $NetBSD: Makefile,v 1.5 2005/04/11 21:47:38 tv Exp $

DISTNAME=	Text-Diff-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	High-level text diffing module for Perl

DEPENDS+=	p5-Algorithm-Diff>=1.15:../../devel/p5-Algorithm-Diff

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
