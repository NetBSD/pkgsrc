# $NetBSD: Makefile,v 1.1.1.1 2007/02/27 13:53:00 wiz Exp $
#

DISTNAME=	File-Which-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Which/
COMMENT=	Portable implementation of the `which' utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
