# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	File-BaseDir-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for the XDG Base Directory Specification


PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/BaseDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
