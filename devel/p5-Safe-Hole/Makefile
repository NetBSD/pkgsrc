# $NetBSD: Makefile,v 1.1.1.1 2001/02/27 19:12:27 jtb Exp $
#

DISTNAME=	Safe-Hole-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/Safe-Hole/Hole.html
COMMENT=	Exec subs in the original package from within a Safe object

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Safe/Hole/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
