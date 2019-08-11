# $NetBSD: Makefile,v 1.35 2019/08/11 13:23:15 wiz Exp $

DISTNAME=	Unix-Syslog-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unix-Syslog
COMMENT=	Perl5 module interface to the UNIX system logger
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
