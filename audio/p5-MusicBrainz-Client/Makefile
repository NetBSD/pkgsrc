# $NetBSD: Makefile,v 1.25 2019/08/11 13:17:56 wiz Exp $

DISTNAME=	MusicBrainz-Client-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Provide access to the libmusicbrainz client library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MusicBrainz-Queries>=0.10:../../audio/p5-MusicBrainz-Queries

PERL5_PACKLIST=		auto/MusicBrainz/Client/.packlist

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
