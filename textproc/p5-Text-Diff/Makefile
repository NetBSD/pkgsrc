# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:42 jlam Exp $

DISTNAME=	Text-Diff-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	High-level text diffing module for Perl

DEPENDS+=	p5-Algorithm-Diff>=1.15:../../devel/p5-Algorithm-Diff

PERL5_PACKLIST=		auto/Text/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
