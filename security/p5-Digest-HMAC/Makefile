# $NetBSD: Makefile,v 1.2 2001/11/30 15:20:45 mjl Exp $
#

DISTNAME=		Digest-HMAC-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for HMAC

DEPENDS+=		p5-Digest-SHA1>=1.00:../p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5>=2.00:../p5-Digest-MD5

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/HMAC/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
