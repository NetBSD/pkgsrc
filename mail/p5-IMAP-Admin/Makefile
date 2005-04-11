# $NetBSD: Makefile,v 1.15 2005/04/11 21:46:21 tv Exp $
#

DISTNAME=       IMAP-Admin-1.6.1
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for administration of RFC-2060 IMAP servers

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
