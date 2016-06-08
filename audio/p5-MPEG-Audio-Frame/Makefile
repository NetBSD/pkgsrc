# $NetBSD: Makefile,v 1.12 2016/06/08 19:22:15 wiz Exp $

DISTNAME=	MPEG-Audio-Frame-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MPEG/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MPEG-Audio-Frame/
COMMENT=	Class for weeding out MPEG audio frames out of a file handle
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MPEG/Audio/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
