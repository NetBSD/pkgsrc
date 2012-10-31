# $NetBSD: Makefile,v 1.4 2012/10/31 11:18:50 asau Exp $

DISTNAME=	PerlIO-via-Bzip2-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PerlIO layer for Bzip2 (de)compression
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-via-Bzip2/
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Compress-Bzip2>=1.03:../../archivers/p5-Compress-Bzip2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/PerlIO/via/Bzip2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
