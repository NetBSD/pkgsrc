# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:14 joerg Exp $
#

DISTNAME=	MusicBrainz-Queries-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Provide access to the Music Brainz RDF Query Constants

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MusicBrainz/Queries/.packlist

.include "../../audio/musicbrainz/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
