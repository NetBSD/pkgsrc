# $NetBSD: Makefile,v 1.4 2002/01/19 03:54:08 mjl Exp $
#

DISTNAME=	Text-Balanced-1.89
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tba
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	Extract delimited text sequences from strings

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Balanced/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
