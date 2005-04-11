# $NetBSD: Makefile,v 1.12 2005/04/11 21:47:38 tv Exp $
#

DISTNAME=	Text-CSV_XS-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tcx
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	http://
COMMENT=	Routines for composition and decomposition of comma-separated values

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/CSV_XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
