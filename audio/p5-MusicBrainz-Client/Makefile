# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:08 tv Exp $
#

DISTNAME=	MusicBrainz-Client-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Provide access to the libmusicbrainz client library

DEPENDS+=	p5-MusicBrainz-Queries>=0.07:../../audio/p5-MusicBrainz-Queries

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MusicBrainz/Client/.packlist

.include "../../audio/musicbrainz/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
