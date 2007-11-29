# $NetBSD: Makefile,v 1.9 2007/11/29 17:38:39 wiz Exp $

DISTNAME=	File-Remove-0.39
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
