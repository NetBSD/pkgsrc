# $NetBSD: Makefile,v 1.27 2023/07/06 09:38:53 wiz Exp $

DISTNAME=	Data-Compare-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Compare
COMMENT=	Perl5 module comparing arbitrary data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Data/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
