# $NetBSD: Makefile,v 1.6 2001/11/26 06:50:14 jlam Exp $
#

DISTNAME=		Crypt-Blowfish-2.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbl
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 Blowfish implementation

CRYPTO=			YES

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Blowfish/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
