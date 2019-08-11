# $NetBSD: Makefile,v 1.16 2019/08/11 13:19:27 wiz Exp $

DISTNAME=	File-Listing-6.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Listing
COMMENT=	Perl 5 module providing a directory parser
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00
DEPENDS+=	p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Listing/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
