# $NetBSD: Makefile,v 1.21 2011/08/14 12:26:29 obache Exp $
#

DISTNAME=	Parse-Yapp-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5pya
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-Yapp/
COMMENT=	Perl5 LALR parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
