# $NetBSD: Makefile,v 1.2 2011/08/14 12:26:31 obache Exp $

DISTNAME=	PerlIO-via-Bzip2-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PerlIO layer for Bzip2 (de)compression
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-via-Bzip2/
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Compress-Bzip2>=1.03:../../archivers/p5-Compress-Bzip2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PerlIO/via/Bzip2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
