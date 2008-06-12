# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:27 joerg Exp $
#

DISTNAME=	Tie-IxHash-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tix
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-IxHash/
COMMENT=	Perl module that implements ordered in-memory associative arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/IxHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
