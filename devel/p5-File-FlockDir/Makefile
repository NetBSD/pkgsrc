# $NetBSD: Makefile,v 1.7 2004/04/25 04:00:10 minskim Exp $
#

DISTNAME=	File-FlockDir-1.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ffl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	FlockDir - override perl flock() for network or portability purposes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/FlockDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
