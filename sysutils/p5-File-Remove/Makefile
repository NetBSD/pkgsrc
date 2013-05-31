# $NetBSD: Makefile,v 1.22 2013/05/31 12:42:02 wiz Exp $

DISTNAME=	File-Remove-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Remove/
COMMENT=	Remove files and directories
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
