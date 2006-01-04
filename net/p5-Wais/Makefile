# $NetBSD: Makefile,v 1.18 2006/01/04 04:29:07 schmonz Exp $
#

DISTNAME=	Wais-2.311
PKGNAME=	p5-Wais-2.311
PKGREVISION=	3
SVR4_PKGNAME=	p5wai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wais/}

MAINTAINER=	bad@NetBSD.org
COMMENT=	Perl5 module for accessing WAIS servers

BROKEN_IN=	pkgsrc-2005Q4

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

PERL5_PACKLIST= auto/Wais/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../net/freewais-sf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
