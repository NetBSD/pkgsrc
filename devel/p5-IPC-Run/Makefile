# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:27 jschauma Exp $

DISTNAME=	IPC-Run-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for interacting with child processes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
