# $NetBSD: Makefile,v 1.12 2001/10/18 15:20:27 veego Exp $

DISTNAME=	MailTools-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mto
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 modules related to mail applications

BUILD_DEPENDS+=	p5-Net>=1.0703:../../net/p5-Net

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
