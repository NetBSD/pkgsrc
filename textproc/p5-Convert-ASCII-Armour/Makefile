# $NetBSD: Makefile,v 1.33 2019/06/30 20:16:47 nia Exp $
#

DISTNAME=		Convert-ASCII-Armour-1.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Convert-ASCII-Armour
COMMENT=		Perl5 module to convert binary octets into ASCII armour

#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
#DEPENDS+=		{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress	# Compress::Zlib>=0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASCII/Armour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
