# $NetBSD: Makefile,v 1.7 2003/06/02 01:16:33 jschauma Exp $
#

DISTNAME=	Text-Balanced-1.94
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tba
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=	Extract delimited text sequences from strings

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
