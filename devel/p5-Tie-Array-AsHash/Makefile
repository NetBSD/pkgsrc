# $NetBSD: Makefile,v 1.9 2014/05/29 23:36:25 wiz Exp $
#

DISTNAME=	Tie-Array-AsHash-0.200
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5taa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-AsHash/
COMMENT=	Perl module to access array(s) like hashes
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Tie/Array/AsHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
