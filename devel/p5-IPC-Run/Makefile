# $NetBSD: Makefile,v 1.2 2002/10/13 22:02:55 seb Exp $

DISTNAME=	IPC-Run-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for interacting with child processes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
