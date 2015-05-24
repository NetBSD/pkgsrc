# $NetBSD: Makefile,v 1.2 2015/05/24 07:33:59 mef Exp $

DISTNAME=	Archive-Tar-Wrapper-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mschilli/Archive-Tar-Wrapper/
COMMENT=	API wrapper around the 'tar' utility
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Archive/Tar/Wrapper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
