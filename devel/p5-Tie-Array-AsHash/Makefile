# $NetBSD: Makefile,v 1.1.1.1 2008/11/09 12:50:10 obache Exp $
#

DISTNAME=	Tie-Array-AsHash-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5taa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-AsHash/
COMMENT=	Perl module to access array(s) like hashes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/Array/AsHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
