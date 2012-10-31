# $NetBSD: Makefile,v 1.15 2012/10/31 11:18:15 asau Exp $

DISTNAME=	FileHandle-Unget-0.1623
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
