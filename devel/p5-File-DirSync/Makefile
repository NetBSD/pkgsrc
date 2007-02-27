# $NetBSD: Makefile,v 1.10 2007/02/27 09:16:14 wiz Exp $
#

DISTNAME=	File-DirSync-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-DirSync/
COMMENT=	Perl5 module to synchronize two directories rapidly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/DirSync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
