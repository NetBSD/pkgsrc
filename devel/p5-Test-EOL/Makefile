# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:42 ryoon Exp $

DISTNAME=	Test-EOL-1.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/F/FR/FREW/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/F/FR/FREW/
COMMENT=	Check the correct line endings in your project

LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=         auto/Test/EOL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
