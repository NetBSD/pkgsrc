# $NetBSD: Makefile,v 1.1.1.1 2002/04/15 12:16:10 he Exp $
#

DISTNAME=		IO-Interface-0.97
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5intf
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@netbsd.org
COMMENT=		IO-Interface - get and set interface characteristics

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
