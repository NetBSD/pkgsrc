# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:49 joerg Exp $

DISTNAME=	Algorithm-Annotate-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module that provides cvs-annotate-like functionality

DEPENDS+=	p5-Algorithm-Diff>=1.15:../../devel/p5-Algorithm-Diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Algorithm/Annotate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
