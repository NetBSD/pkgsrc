# $NetBSD: Makefile,v 1.10 2003/07/17 22:53:44 grant Exp $

DISTNAME=	Unix-Syslog-0.99
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sl
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	perl5 module interface to the UNIX system logger

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
