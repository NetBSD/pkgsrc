# $NetBSD: Makefile,v 1.12 2004/04/25 03:43:02 snj Exp $

DISTNAME=	Unix-Syslog-0.99
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sl
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module interface to the UNIX system logger

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
