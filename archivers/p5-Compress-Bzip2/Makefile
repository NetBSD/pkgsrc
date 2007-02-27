# $NetBSD: Makefile,v 1.11 2007/02/27 08:59:10 wiz Exp $
#

DISTNAME=	Compress-Bzip2-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AR/ARJAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
