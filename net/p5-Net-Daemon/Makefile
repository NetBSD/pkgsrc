# $NetBSD: Makefile,v 1.2 2001/09/05 17:18:22 jlam Exp $
#

DISTNAME=	Net-Daemon-0.34
PKGNAME=	p5-Net-Daemon-0.34
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=	perl5 module for writing networking daemons

DEPENDS+= 	{p5-Data-Dumper-*,perl>=5.6.1nb2}:../../lang/perl5

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Daemon/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
