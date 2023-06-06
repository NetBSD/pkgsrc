# $NetBSD: Makefile,v 1.23 2023/06/06 12:41:06 riastradh Exp $
#

DISTNAME=		Test-File-1.993
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-File
COMMENT=		Test file attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/File/.packlist

TOOL_DEPENDS+=		p5-Test-utf8>=0:../../devel/p5-Test-utf8

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
