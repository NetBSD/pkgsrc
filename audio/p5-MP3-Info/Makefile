# $NetBSD: Makefile,v 1.3 2002/10/20 17:46:02 seb Exp $

DISTNAME=	MP3-Info-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?module=MP3::Info
COMMENT=	Manipulate / fetch info from MP3 audio files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
