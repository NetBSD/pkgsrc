# $NetBSD: Makefile,v 1.4 2017/06/05 14:22:18 ryoon Exp $

DISTNAME=	MusicBrainz-DiscID-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~njh/MusicBrainz-DiscID/
COMMENT=	Perl interface for the MusicBrainz libdiscid library
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/MusicBrainz/DiscID/.packlist

PERL5_MODULE_TYPE=	Module::Build
USE_TOOLS+=	pkg-config

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
