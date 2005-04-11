# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:38 tv Exp $
#

DISTNAME=	String-CRC32-1.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5c32
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=String::CRC32
COMMENT=	Perl module to generate cksums from strings and from files

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/CRC32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
