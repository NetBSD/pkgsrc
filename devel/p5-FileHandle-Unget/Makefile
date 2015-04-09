# $NetBSD: Makefile,v 1.18 2015/04/09 01:28:23 mef Exp $

DISTNAME=	FileHandle-Unget-0.1625
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/FileHandle/Unget/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

# for tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
