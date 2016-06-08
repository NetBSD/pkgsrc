# $NetBSD: Makefile,v 1.23 2016/06/08 19:24:34 wiz Exp $
#

DISTNAME=	String-CRC32-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=String::CRC32
COMMENT=	Perl module to generate cksums from strings and from files
LICENSE=	public-domain

PERL5_PACKLIST=		auto/String/CRC32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
