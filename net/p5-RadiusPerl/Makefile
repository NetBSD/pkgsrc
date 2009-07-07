# $NetBSD: Makefile,v 1.3 2009/07/07 16:15:31 sno Exp $
#

DISTNAME=	RadiusPerl-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/
COMMENT=	Provide simple Radius client facilities
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-0.13
PERL5_PACKLIST=	auto/Authen/Radius/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
