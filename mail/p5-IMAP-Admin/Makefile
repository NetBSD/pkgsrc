# $NetBSD: Makefile,v 1.9 2003/06/02 01:18:42 jschauma Exp $
#

DISTNAME=       IMAP-Admin-1.6.1
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	perl5 module for administration of RFC-2060 IMAP servers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
