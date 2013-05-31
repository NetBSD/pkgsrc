# $NetBSD: Makefile,v 1.20 2013/05/31 12:39:35 wiz Exp $

DISTNAME=	Compress-Bzip2-2.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RU/RURBAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
