# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:34 tv Exp $

DISTNAME=	SVN-Simple-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple interface to the Subversion delta editor interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
