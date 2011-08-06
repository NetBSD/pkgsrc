# $NetBSD: Makefile,v 1.9 2011/08/06 12:48:30 adam Exp $

DISTNAME=	Audio-Scan-0.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Audio-Scan/
COMMENT=	XS parser for MP3, MP4, Ogg Vorbis, etc
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Audio/Scan/.packlist
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
