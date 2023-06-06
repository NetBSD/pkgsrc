# $NetBSD: Makefile,v 1.29 2023/06/06 12:40:17 riastradh Exp $

DISTNAME=	Audio-Scan-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://metacpan.org/release/Audio-Scan
COMMENT=	XS parser for MP3, MP4, Ogg Vorbis, etc
LICENSE=	gnu-gpl-v2

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Audio/Scan/.packlist
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
