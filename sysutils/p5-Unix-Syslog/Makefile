# $NetBSD: Makefile,v 1.26 2012/10/23 19:51:19 asau Exp $

DISTNAME=	Unix-Syslog-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5sl
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unix-Syslog/
COMMENT=	Perl5 module interface to the UNIX system logger
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
