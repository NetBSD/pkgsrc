# $NetBSD: Makefile,v 1.17 2009/04/11 23:15:21 sno Exp $
#

DISTNAME=		Convert-ASCII-Armour-1.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5cas
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASCII-Armour/
COMMENT=		Perl5 module to convert binary octets into ASCII armour

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-IO-Compress-[0-9]:../../devel/p5-IO-Compress

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASCII/Armour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
