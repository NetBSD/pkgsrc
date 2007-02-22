# $NetBSD: Makefile,v 1.19 2007/02/22 19:26:42 wiz Exp $
#

DISTNAME=	IMAP-Admin-1.6.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for administration of RFC-2060 IMAP servers

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
