# $NetBSD: Makefile,v 1.8 2002/10/07 21:11:40 seb Exp $
#

DISTNAME=       IMAP-Admin-1.6.1
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for administration of RFC-2060 IMAP servers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
