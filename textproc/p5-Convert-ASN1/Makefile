# $NetBSD: Makefile,v 1.6 2001/10/01 16:33:54 wiz Exp $
#

DISTNAME=		Convert-ASN1-0.14
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module to encode/decode ASN.1 data

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/ASN1/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
