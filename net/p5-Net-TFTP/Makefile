# $NetBSD: Makefile,v 1.13 2005/04/11 21:46:56 tv Exp $

DISTNAME=	Net-TFTP-0.10
PKGNAME=	p5-Net-TFTP-0.10
SVR4_PKGNAME=	p5ntf
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for TFTP transfers

WRKSRC=			${WRKDIR}/Net-TFTP-0.10
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
