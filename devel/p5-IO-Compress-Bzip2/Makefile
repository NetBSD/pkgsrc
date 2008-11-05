# $NetBSD: Makefile,v 1.1.1.1 2008/11/05 15:41:14 wiz Exp $

DISTNAME=		IO-Compress-Bzip2-2.015
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Compress-Bzip2/
COMMENT=		Perl module to parse bzip2 files and buffers

DEPENDS+=		p5-IO-Compress-Base>=2.015:../../devel/p5-IO-Compress-Base
DEPENDS+=		p5-Compress-Raw-Bzip2>=2.015:../../devel/p5-Compress-Raw-Bzip2

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Compress/Bzip2/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
