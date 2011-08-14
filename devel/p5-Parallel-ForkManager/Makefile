# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:27 obache Exp $
#

DISTNAME=	Parallel-ForkManager-0.7.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
