# $NetBSD: Makefile,v 1.21 2023/07/06 09:38:10 wiz Exp $

DISTNAME=	MPEG-Audio-Frame-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MPEG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MPEG-Audio-Frame
COMMENT=	Class for weeding out MPEG audio frames out of a file handle
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MPEG/Audio/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
