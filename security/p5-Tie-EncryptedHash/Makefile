# $NetBSD: Makefile,v 1.1 2001/10/01 15:17:58 mcr Exp $
#

DISTNAME=		Tie-EncryptedHash-1.1
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for hashes with encrypting fields

DEPENDS+=		p5-Crypt-CBC-*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Blowfish-*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-*:../../security/p5-Crypt-DES

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tie/EncryptedHash/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
