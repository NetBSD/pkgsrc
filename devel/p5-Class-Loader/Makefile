# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:13 veego Exp $
#

DISTNAME=		Class-Loader-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clo
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		mcr@netbsd.org
#	from sen_ml@eccosys.com
#HOMEPAGE=	
COMMENT=		perl5 module for module loading and on-demand object creation

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Loader/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
