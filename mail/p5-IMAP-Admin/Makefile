# $NetBSD: Makefile,v 1.12 2004/05/02 04:19:41 snj Exp $
#

DISTNAME=       IMAP-Admin-1.6.1
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for administration of RFC-2060 IMAP servers

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
