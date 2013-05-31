# $NetBSD: Makefile,v 1.22 2013/05/31 12:40:20 wiz Exp $

DISTNAME=	File-PathConvert-0.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5fpc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-PathConvert/
COMMENT=	Convert paths and URLs from absolute to relative and vice versa
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/PathConvert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
