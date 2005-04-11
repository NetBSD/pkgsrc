# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:31 tv Exp $
#

DISTNAME=	File-DirSync-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to synchronize two directories rapidly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/DirSync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
