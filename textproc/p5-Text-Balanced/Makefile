# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:22 jlam Exp $
#

DISTNAME=	Text-Balanced-1.85
PKGNAME=	p5-Text-Balanced-1.85
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
