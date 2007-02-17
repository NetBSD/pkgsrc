# $NetBSD: Makefile,v 1.14 2007/02/17 20:59:49 wiz Exp $

DISTNAME=	SVN-Simple-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple interface to the Subversion delta editor interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
