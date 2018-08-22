# $NetBSD: Makefile,v 1.15 2018/08/22 09:44:52 wiz Exp $
#

DISTNAME=	Tie-Array-AsHash-0.200
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-AsHash/
COMMENT=	Perl module to access array(s) like hashes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Tie/Array/AsHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
