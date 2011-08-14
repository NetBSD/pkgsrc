# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:39 obache Exp $

DISTNAME=	Term-Screen-1.03
PKGNAME=	p5-Term-Screen-1.03
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Screen/
COMMENT=	Term::Cap based screen positioning module

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/Screen/.packlist

# Asks the user to first don't press a key and then to press a key.
INTERACTIVE_STAGE=	test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
