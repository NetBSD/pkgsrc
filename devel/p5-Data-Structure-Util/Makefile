# $NetBSD: Makefile,v 1.2 2017/06/05 14:22:49 ryoon Exp $

DISTNAME=	Data-Structure-Util-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AN/ANDYA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AN/ANDYA/
COMMENT=	Change nature of data within a structure
LICENSE=        ${PERL5_LICENSE}

PERL5_PACKLIST= auto/Data/Structure/Util/.packlist
USE_LANGUAGES=  c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
