# $NetBSD: Makefile,v 1.1 2017/01/30 14:13:23 mef Exp $

DISTNAME=	File-Flock-2014.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/
COMMENT=	File::Flock - file locking with flock
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/File/Flock/.packlist
USE_LANGUAGES=  # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
