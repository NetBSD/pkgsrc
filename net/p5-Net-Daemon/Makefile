# $NetBSD: Makefile,v 1.8 2002/07/24 19:45:26 jlam Exp $
#

DISTNAME=	Net-Daemon-0.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=	perl5 module for writing networking daemons

DEPENDS+= 	{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:${PERL5_PKGSRCDIR}

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Daemon/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
