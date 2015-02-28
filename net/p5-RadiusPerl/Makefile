# $NetBSD: Makefile,v 1.12 2015/02/28 14:37:01 mef Exp $
#

DISTNAME=	RadiusPerl-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RadiusPerl/
COMMENT=	Provide simple Radius client facilities
LICENSE=	artistic-2.0

DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-${PKGVERSION_NOREV}
PERL5_PACKLIST=	auto/Authen/Radius/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
