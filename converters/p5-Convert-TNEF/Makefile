# $NetBSD: Makefile,v 1.2 2001/10/23 19:27:31 veego Exp $

DISTNAME=		Convert-TNEF-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tnf
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to read TNEF files

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/TNEF/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
