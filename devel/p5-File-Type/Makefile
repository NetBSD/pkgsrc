# $NetBSD: Makefile,v 1.12 2012/10/03 21:55:03 wiz Exp $

DISTNAME=	File-Type-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining file type
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
