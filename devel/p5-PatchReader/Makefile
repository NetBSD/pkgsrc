# $NetBSD: Makefile,v 1.5 2005/08/06 06:19:13 jlam Exp $

DISTNAME=	PatchReader-0.9.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JK/JKEISER/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jkeiser/${DISTNAME}
COMMENT=	Utilities to read and manipulate patches and CVS

PERL5_PACKLIST=	auto/PatchReader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
