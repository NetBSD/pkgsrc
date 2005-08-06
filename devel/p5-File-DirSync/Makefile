# $NetBSD: Makefile,v 1.8 2005/08/06 06:19:10 jlam Exp $
#

DISTNAME=	File-DirSync-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to synchronize two directories rapidly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/DirSync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
