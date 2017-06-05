# $NetBSD: Makefile,v 1.14 2017/06/05 14:24:14 ryoon Exp $

DISTNAME=		File-MMagic-XS-0.09008
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic-XS/
COMMENT=		File Type With XS (a la mod_mime_magic)
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Module-Install-AuthorTests-[0-9]*:../../devel/p5-Module-Install-AuthorTests
BUILD_DEPENDS+=		p5-Module-Install-Repository-[0-9]*:../../devel/p5-Module-Install-Repository
BUILD_DEPENDS+=		p5-Module-Install-XSUtil-[0-9]*:../../devel/p5-Module-Install-XSUtil

MAKE_JOBS_SAFE=		no

PERL5_PACKLIST=		auto/File/MMagic/XS/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
