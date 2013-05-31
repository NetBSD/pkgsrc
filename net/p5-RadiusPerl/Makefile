# $NetBSD: Makefile,v 1.10 2013/05/31 12:41:41 wiz Exp $
#

DISTNAME=	RadiusPerl-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RadiusPerl/
COMMENT=	Provide simple Radius client facilities
LICENSE=	artistic-2.0

DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-0.17
PERL5_PACKLIST=	auto/Authen/Radius/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
