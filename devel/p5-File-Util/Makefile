# $NetBSD: Makefile,v 1.21 2020/08/31 18:08:04 wiz Exp $
#

DISTNAME=	File-Util-4.201720
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Util
COMMENT=	Perl extension for easy, versatile, portable file handling
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Handler>=1:../../devel/p5-Exception-Handler

PERL5_PACKLIST=		auto/File/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
