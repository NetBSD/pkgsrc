# $NetBSD: Makefile,v 1.5 2004/04/25 03:44:35 minskim Exp $

DISTNAME=	IPC-Run-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for interacting with child processes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
