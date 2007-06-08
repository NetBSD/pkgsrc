# $NetBSD: Makefile,v 1.5 2007/06/08 08:44:55 wiz Exp $

DISTNAME=	File-NCopy-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHORNY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-NCopy/
COMMENT=	Copy files and directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/File/NCopy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
