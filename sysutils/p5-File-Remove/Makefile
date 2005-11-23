# $NetBSD: Makefile,v 1.6 2005/11/23 22:07:30 wiz Exp $

DISTNAME=	File-Remove-0.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Remove/
COMMENT=	Remove files and directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
