# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:22 jlam Exp $
#

DISTNAME=       Pod-POM-0.02
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	p5 module to format POD into an object format, hence POM

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pod/POM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
