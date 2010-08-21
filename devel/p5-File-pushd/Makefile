# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:47 seb Exp $
#

DISTNAME=		File-pushd-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
