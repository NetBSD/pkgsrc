# $NetBSD: Makefile,v 1.29 2003/03/17 01:29:32 seb Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	libnet-1.13
PKGNAME=	p5-Net-1.13
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/Net/libnetFAQ.html
COMMENT=	perl5 modules to access and use network protocols

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
