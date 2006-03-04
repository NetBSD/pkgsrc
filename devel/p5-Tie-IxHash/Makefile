# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:25 jlam Exp $
#

DISTNAME=      	Tie-IxHash-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tix
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-IxHash/
COMMENT=	Perl module that implements ordered in-memory associative arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Tie/IxHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
