# $NetBSD: Makefile,v 1.6 2002/01/28 02:34:02 wiz Exp $

DISTNAME=		Unix-Syslog-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sl
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to the UNIX system logger

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
