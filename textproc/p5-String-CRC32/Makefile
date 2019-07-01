# $NetBSD: Makefile,v 1.28 2019/07/01 21:35:54 nia Exp $
#

DISTNAME=	String-CRC32-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/search?q=module%3AString%3A%3ACRC32
COMMENT=	Perl module to generate cksums from strings and from files
LICENSE=	public-domain

PERL5_PACKLIST=		auto/String/CRC32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
