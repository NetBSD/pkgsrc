# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:53 jlam Exp $
#

DISTNAME=      	Parse-Yapp-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p6pya
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 LALR parser

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/Yapp/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
