# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:32 ryoon Exp $
#

DISTNAME=	Template-DBI-2.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-DBI/
COMMENT=	Template interface to the DBI module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2.15:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Tie-DBI>=1.05:../../databases/p5-Tie-DBI # only with patches

PERL5_PACKLIST=		auto/Template/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
