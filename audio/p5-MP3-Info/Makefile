# $NetBSD: Makefile,v 1.18 2010/08/21 16:32:44 seb Exp $

DISTNAME=	MP3-Info-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MP3-Info/
COMMENT=	Manipulate/fetch info from MP3 audio files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/MP3/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
