# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:31 tv Exp $

DISTNAME=	File-BaseDir-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for the XDG Base Directory Specification


PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/BaseDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
