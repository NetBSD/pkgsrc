# $NetBSD: Makefile,v 1.15 2005/06/24 06:43:45 jlam Exp $
#

DISTNAME=	Net-Daemon-0.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nda
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=	Perl5 module for writing networking daemons

DEPENDS+= 	{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:../../lang/perl5

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
