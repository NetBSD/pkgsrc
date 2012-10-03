# $NetBSD: Makefile,v 1.7 2012/10/03 21:53:57 wiz Exp $

DISTNAME=	MPEG-Audio-Frame-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MPEG/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MPEG-Audio-Frame/
COMMENT=	Class for weeding out MPEG audio frames out of a file handle
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/MPEG/Audio/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
