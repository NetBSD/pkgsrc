# $NetBSD: Makefile,v 1.7 2003/07/17 22:51:34 grant Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	Net-TFTP-0.10
PKGNAME=	p5-Net-TFTP-0.10
SVR4_PKGNAME=	p5ntf
WRKSRC=		${WRKDIR}/Net-TFTP-0.10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	perl5 module for TFTP transfers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
