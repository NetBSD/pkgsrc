# $NetBSD: Makefile,v 1.5 2003/06/02 01:20:31 jschauma Exp $
#

DISTNAME=	File-FlockDir-1.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ffl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	FlockDir - override perl flock() for network or portability purposes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/FlockDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
