# $NetBSD: Makefile,v 1.3 2013/07/03 06:13:29 sno Exp $
#

DISTNAME=	Sys-Syslog-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://search.cpan.org/dist/Sys-Syslog/
COMMENT=	Perl interface to the UNIX syslog(3) calls
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader>=0:../../devel/p5-XSLoader

PERL5_PACKLIST=	auto/Sys/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
