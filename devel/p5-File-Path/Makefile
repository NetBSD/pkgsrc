# $NetBSD: Makefile,v 1.9 2014/05/29 23:35:55 wiz Exp $

DISTNAME=	File-Path-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5fpc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path/
COMMENT=	Perl5 module to create or remove directory trees
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
