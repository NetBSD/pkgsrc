# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:37 ryoon Exp $
#

DISTNAME=	Sys-Syslog-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://search.cpan.org/dist/Sys-Syslog/
COMMENT=	Perl interface to the UNIX syslog(3) calls
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.6.0,p5-XSLoader>=0}:../../devel/p5-XSLoader

PERL5_PACKLIST=	auto/Sys/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
