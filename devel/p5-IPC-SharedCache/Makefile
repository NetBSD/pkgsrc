# $NetBSD: Makefile,v 1.1.1.1 2002/03/19 07:22:31 cjs Exp $
#

DISTNAME=	IPC-SharedCache-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Cache data in shared memory

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite

USE_BUILDLINK_ONLY=	 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/SharedCache/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL </dev/null

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
