# $NetBSD: Makefile,v 1.19 2001/09/05 17:18:22 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	libnet-1.0703
PKGNAME=	p5-Net-1.0703
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/Net/libnetFAQ.html  
COMMENT=	perl5 modules to access and use network protocols

DEPENDS+= 	{p5-Data-Dumper-*,perl>=5.6.1nb2}:../../lang/perl5

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
