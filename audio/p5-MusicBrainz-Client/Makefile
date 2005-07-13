# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:19 jlam Exp $
#

DISTNAME=	MusicBrainz-Client-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Provide access to the libmusicbrainz client library

DEPENDS+=	p5-MusicBrainz-Queries>=0.07:../../audio/p5-MusicBrainz-Queries

PERL5_PACKLIST=		auto/MusicBrainz/Client/.packlist

.include "../../audio/musicbrainz/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
