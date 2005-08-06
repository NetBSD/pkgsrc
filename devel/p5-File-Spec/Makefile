# $NetBSD: Makefile,v 1.7 2005/08/06 06:19:10 jlam Exp $
#

DISTNAME=	File-Spec-0.90
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fsp
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Spec/
COMMENT=	Portably perform operations on file names

PERL5_PACKLIST=		auto/File/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
