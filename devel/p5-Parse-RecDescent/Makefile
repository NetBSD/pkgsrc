# $NetBSD: Makefile,v 1.4 2003/06/02 01:20:23 jschauma Exp $
#

DISTNAME=	Parse-RecDescent-1.94
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=		generate recursive-descent parsers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/RecDescent/.packlist

DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
