# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:37 veego Exp $
#

DISTNAME=		Digest-MD2-2.00
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD2/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
