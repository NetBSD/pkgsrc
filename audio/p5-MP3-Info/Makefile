# $NetBSD: Makefile,v 1.1.1.1 2002/03/02 02:30:34 rxg Exp $

DISTNAME=	MP3-Info-1.00
PKGNAME=	p5-MP3-Info-1.00
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?module=MP3::Info
COMMENT=	Manipulate / fetch info from MP3 audio files

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Info/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
