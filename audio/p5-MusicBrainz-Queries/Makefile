# $NetBSD: Makefile,v 1.1.1.1 2004/08/29 21:53:25 epg Exp $
#

DISTNAME=	MusicBrainz-Queries-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Provide access to the Music Brainz RDF Query Constants

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MusicBrainz/Queries/.packlist

.include "../../audio/musicbrainz/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
