# $NetBSD: Makefile,v 1.10 2011/08/14 12:26:06 obache Exp $

DISTNAME=	File-Type-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining file type

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
