# $NetBSD: Makefile,v 1.3 2004/12/05 19:18:07 he Exp $
#

DISTNAME=	File-Spec-0.90
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fsp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Spec/
COMMENT=	Portably perform operations on file names

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
