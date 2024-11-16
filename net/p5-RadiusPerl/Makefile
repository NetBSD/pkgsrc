# $NetBSD: Makefile,v 1.23 2024/11/16 12:06:20 wiz Exp $
#

DISTNAME=	RadiusPerl-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/RadiusPerl
COMMENT=	Provide simple Radius client facilities
LICENSE=	artistic-2.0

DEPENDS+=	p5-Data-HexDump>=0.02:../../textproc/p5-Data-HexDump

WRKSRC=		${WRKDIR}/Authen-Radius-${PKGVERSION_NOREV}
PERL5_PACKLIST=	auto/Authen/Radius/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
