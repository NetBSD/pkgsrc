# $NetBSD: Makefile,v 1.6 2012/10/31 11:19:12 asau Exp $
#

DISTNAME=	Tie-Array-AsHash-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5taa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-AsHash/
COMMENT=	Perl module to access array(s) like hashes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Tie/Array/AsHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
