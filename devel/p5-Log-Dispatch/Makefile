# $NetBSD: Makefile,v 1.5 2002/10/13 22:22:47 seb Exp $

DISTNAME=	Log-Dispatch-1.79
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl module for logging messages to multiple outputs

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
