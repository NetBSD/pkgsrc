# $NetBSD: Makefile,v 1.1.1.1 2010/02/08 21:06:29 wiz Exp $
#

DISTNAME=	Audio-Scan-0.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Audio-Scan/
COMMENT=	XS parser for MP3, MP4, Ogg Vorbis, etc
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Audio/Scan/.packlist
USE_LIBTOOL=		yes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
