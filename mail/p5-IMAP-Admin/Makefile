# $NetBSD: Makefile,v 1.41 2022/06/28 11:34:27 wiz Exp $
#

DISTNAME=	IMAP-Admin-1.6.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IMAP-Admin
COMMENT=	Perl5 module for administration of RFC-2060 IMAP servers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
