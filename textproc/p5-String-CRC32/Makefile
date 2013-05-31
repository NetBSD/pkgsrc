# $NetBSD: Makefile,v 1.18 2013/05/31 12:42:13 wiz Exp $
#

DISTNAME=	String-CRC32-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5c32
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=String::CRC32
COMMENT=	Perl module to generate cksums from strings and from files

PERL5_PACKLIST=		auto/String/CRC32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
