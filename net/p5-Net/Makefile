# $NetBSD: Makefile,v 1.26 2002/04/17 10:36:22 shell Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	libnet-1.11
PKGNAME=	p5-Net-1.11
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/Net/libnetFAQ.html
COMMENT=	perl5 modules to access and use network protocols

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
