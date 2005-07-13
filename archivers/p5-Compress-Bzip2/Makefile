# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:18 jlam Exp $
#

DISTNAME=	Compress-Bzip2-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/K/KC/KCARNUT/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
