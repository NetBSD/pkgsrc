# $NetBSD: Makefile,v 1.5 2003/06/02 01:21:35 jschauma Exp $

DISTNAME=	MP3-Info-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?module=MP3::Info
COMMENT=	Manipulate / fetch info from MP3 audio files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
