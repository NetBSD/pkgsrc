# $NetBSD: Makefile,v 1.14 2005/04/11 21:47:28 tv Exp $

DISTNAME=	Unix-Syslog-0.99
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sl
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module interface to the UNIX system logger

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
