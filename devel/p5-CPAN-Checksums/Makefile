# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 14:15:52 sno Exp $

DISTNAME=	CPAN-Checksums-2.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Checksums/
COMMENT=	Write a CHECKSUMS file for a directory as on CPAN
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

DEPENDS+=	p5-Compress-Bzip2-[0-9]*:../../archivers/p5-Compress-Bzip2
DEPENDS+=	p5-Data-Compare-[0-9]*:../../devel/p5-Data-Compare

PERL5_PACKLIST=		auto/CPAN/Checksums/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
