# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:29 tv Exp $

DISTNAME=	Algorithm-Merge-0.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jsmith/Algorithm-Merge-0.05/
COMMENT=	Perl module providing diff3(1)-like functionality

DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Algorithm/Merge/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
