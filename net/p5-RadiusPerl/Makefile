# $NetBSD: Makefile,v 1.7 2011/08/14 14:14:48 obache Exp $
#

DISTNAME=	RadiusPerl-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RadiusPerl/
COMMENT=	Provide simple Radius client facilities
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-0.17
PERL5_PACKLIST=	auto/Authen/Radius/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
