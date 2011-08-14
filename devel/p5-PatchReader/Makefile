# $NetBSD: Makefile,v 1.10 2011/08/14 12:26:29 obache Exp $

DISTNAME=	PatchReader-0.9.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JK/JKEISER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jkeiser/${DISTNAME}
COMMENT=	Utilities to read and manipulate patches and CVS

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/PatchReader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
