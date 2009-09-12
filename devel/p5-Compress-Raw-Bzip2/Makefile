# $NetBSD: Makefile,v 1.6 2009/09/12 18:21:57 sno Exp $

DISTNAME=		Compress-Raw-Bzip2-2.021
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Compress-Raw-Bzip2/
COMMENT=		Perl5 low-level interface to bzip2 compression library
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Compress/Raw/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
