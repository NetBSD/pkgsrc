# $NetBSD: Makefile,v 1.2 2002/10/20 23:35:10 seb Exp $
#

DISTNAME=	IPC-SharedCache-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Cache data in shared memory

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite

USE_BUILDLINK2=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/SharedCache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
