# $NetBSD: Makefile,v 1.1.1.1 2002/08/28 19:33:20 seb Exp $

DISTNAME=	IPC-Run-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for interacting with child processes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Run/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
