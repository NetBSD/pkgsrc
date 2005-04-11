# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=	Tree-Simple-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple extension to manipulate tree objects

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
