# $NetBSD: Makefile,v 1.1.1.1 2003/09/04 13:35:19 xtraeme Exp $
#

DISTNAME=	Compress-Bzip2-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/Z/ZO/ZOOVY/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library

USE_BUILDLINK2=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Bzip2/.packlist

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
