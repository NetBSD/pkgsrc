# $NetBSD: Makefile,v 1.8 2002/10/06 22:31:09 seb Exp $

DISTNAME=	Unix-Syslog-0.99
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sl
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module interface to the UNIX system logger

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
