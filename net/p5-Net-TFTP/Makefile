# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:59 wiz Exp $

DISTNAME=	Net-TFTP-0.10
PKGNAME=	p5-Net-TFTP-0.10
SVR4_PKGNAME=	p5ntf
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for TFTP transfers

WRKSRC=			${WRKDIR}/Net-TFTP-0.10
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
