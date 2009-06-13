# $NetBSD: Makefile,v 1.2 2009/06/13 06:46:46 rillig Exp $
#

DISTNAME=	Parallel-ForkManager-0.7.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dlux/Parallel-ForkManager-0.7.5/
COMMENT=	Simple parallel processing fork manager

PKG_DESTDIR_SUPPORT=	user-destdir
REPLACE_PERL+=		*/*.pl

PERL5_PACKLIST=	auto/Parallel/ForkManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
