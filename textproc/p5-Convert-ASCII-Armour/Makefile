# $NetBSD: Makefile,v 1.5 2002/10/20 17:46:04 seb Exp $
#

DISTNAME=		Convert-ASCII-Armour-1.4
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cas
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module to convert binary octets into ASCII armour

DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/ASCII/Armour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
