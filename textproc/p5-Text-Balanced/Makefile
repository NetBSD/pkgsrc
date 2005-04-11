# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:38 tv Exp $
#

DISTNAME=	Text-Balanced-1.94
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tba
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Extract delimited text sequences from strings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
