# $NetBSD: Makefile,v 1.2 2004/02/19 22:13:37 minskim Exp $
#

DISTNAME=	File-Spec-0.86
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fsp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Portably perform operations on file names

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
