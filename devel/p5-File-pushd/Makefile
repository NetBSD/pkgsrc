# $NetBSD: Makefile,v 1.1 2009/03/01 23:25:15 sno Exp $
#

DISTNAME=		File-pushd-1.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-pushd/
COMMENT=		Perl module to change directory temporarily for a limited scope

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/pushd/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
