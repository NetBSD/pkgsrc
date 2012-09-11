# $NetBSD: Makefile,v 1.17 2012/09/11 19:46:59 asau Exp $

DISTNAME=	Compress-Bzip2-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AR/ARJAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
