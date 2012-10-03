# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:27 wiz Exp $

DISTNAME=	Parallel-ForkManager-0.7.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parallel-ForkManager/
COMMENT=	Simple parallel processing fork manager

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Parallel/ForkManager/.packlist
REPLACE_PERL+=		*/*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
