# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=	Parse-Yapp-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pya
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 LALR parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
