# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:15 veego Exp $
#

DISTNAME=	File-FlockDir-1.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ffl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
COMMENT=	FlockDir - override perl flock() for network or portability purposes

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/FlockDir/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
