# $NetBSD: Makefile,v 1.15 2000/07/03 11:30:20 mjl Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	libnet-1.0703
PKGNAME=	p5-Net-1.0703
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html

DEPENDS+= 	p5-Data-Dumper-*:../../devel/p5-Data-Dumper

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
