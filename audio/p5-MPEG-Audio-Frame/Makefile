# $NetBSD: Makefile,v 1.15 2019/06/30 20:14:14 nia Exp $

DISTNAME=	MPEG-Audio-Frame-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MPEG/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MPEG-Audio-Frame
COMMENT=	Class for weeding out MPEG audio frames out of a file handle
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MPEG/Audio/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
