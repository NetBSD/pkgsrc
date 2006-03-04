# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:24 jlam Exp $

DISTNAME=	Term-Screen-1.03
PKGNAME=	p5-Term-Screen-1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Screen/
COMMENT=	Term::Cap based screen positioning module

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=		auto/Term/Screen/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
