# $NetBSD: Makefile,v 1.1.1.1 2009/01/04 00:31:51 adrianp Exp $
#

DISTNAME=	RadiusPerl-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MANOWAR/
COMMENT=	Provide simple Radius client facilities

DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO>=1.12:../../devel/p5-IO
DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-0.13
PERL5_PACKLIST=	auto/RadiusPerl/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
