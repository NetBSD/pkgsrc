# $NetBSD: Makefile,v 1.5 2000/08/27 07:11:14 jlam Exp $

DISTNAME=	MailTools-1.13
PKGNAME=	p5-MailTools-1.13
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS+	${PERL5_SITEARCH}/auto/Net/.packlist:../../net/p5-Net

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
