# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:44 jlam Exp $

DISTNAME=	AppConfig-1.52
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/ABW/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	perl5 module for parsing config files and command line arguments

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/AppConfig/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
