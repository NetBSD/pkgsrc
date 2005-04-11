# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:31 tv Exp $
#

DISTNAME=	File-Spec-0.90
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fsp
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Spec/
COMMENT=	Portably perform operations on file names

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
