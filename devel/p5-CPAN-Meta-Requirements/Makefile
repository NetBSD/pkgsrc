# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:06 wiz Exp $

DISTNAME=	CPAN-Meta-Requirements-2.122
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Meta-Requirements/
COMMENT=	Set of version requirements for a CPAN dist
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-CPAN-Meta<2.120921

PERL5_PACKLIST=		auto/CPAN/Meta/Requirements/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
