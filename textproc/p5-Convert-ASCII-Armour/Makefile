# $NetBSD: Makefile,v 1.1 2001/10/02 01:46:00 mcr Exp $
#

DISTNAME=		Convert-ASCII-Armour-1.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module to convert binary octets into ASCII armour

DEPENDS+=		p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=		p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Compress-Zlib-*:../../devel/p5-Compress-Zlib

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/ASCII/Armour/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
