# $NetBSD: Makefile,v 1.11 2011/11/19 03:27:44 hiramatsu Exp $

DISTNAME=	PatchReader-0.9.6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TM/TMANNERM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PatchReader/
COMMENT=	Utilities to read and manipulate patches and CVS

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/PatchReader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
