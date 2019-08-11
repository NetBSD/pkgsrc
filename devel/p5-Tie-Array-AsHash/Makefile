# $NetBSD: Makefile,v 1.17 2019/08/11 13:20:40 wiz Exp $
#

DISTNAME=	Tie-Array-AsHash-0.200
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Array-AsHash
COMMENT=	Perl module to access array(s) like hashes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Tie/Array/AsHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
