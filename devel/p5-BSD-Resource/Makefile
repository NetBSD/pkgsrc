# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:45 jlam Exp $

DISTNAME=		BSD-Resource-1.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bsd
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://iki.fi/jhi/
COMMENT=		BSD::Resource - Perl interface to BSD process resources library

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/BSD/Resource/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
