# $NetBSD: Makefile,v 1.20 2014/05/29 23:35:54 wiz Exp $
#

DISTNAME=	File-FlockDir-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5ffl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FlockDir - override perl flock() for network or portability purposes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/FlockDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
