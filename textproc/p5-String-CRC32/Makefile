# $NetBSD: Makefile,v 1.20 2014/05/29 23:37:40 wiz Exp $
#

DISTNAME=	String-CRC32-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5c32
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=String::CRC32
COMMENT=	Perl module to generate cksums from strings and from files
LICENSE=	public-domain

PERL5_PACKLIST=		auto/String/CRC32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
