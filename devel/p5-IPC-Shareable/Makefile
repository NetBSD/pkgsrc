# $NetBSD: Makefile,v 1.1 2002/03/15 06:24:29 cjs Exp $
#

DISTNAME=	IPC-Shareable-0.60
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Tie a variable to shared memory

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

USE_BUILDLINK_ONLY=	 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Shareable/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL </dev/null

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
