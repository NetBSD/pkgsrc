# $NetBSD: Makefile,v 1.13 2004/12/20 11:31:07 grant Exp $
#

DISTNAME=	Wais-2.311
PKGNAME=	p5-Wais-2.311
PKGREVISION=	2
SVR4_PKGNAME=	p5wai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wais/}

MAINTAINER=	bad@NetBSD.org
COMMENT=	Perl5 module for accessing WAIS servers

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

USE_BUILDLINK3=	YES
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Wais/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../net/freewais-sf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
