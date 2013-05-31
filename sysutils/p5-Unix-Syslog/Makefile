# $NetBSD: Makefile,v 1.27 2013/05/31 12:42:04 wiz Exp $

DISTNAME=	Unix-Syslog-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
