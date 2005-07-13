# $NetBSD: Makefile,v 1.25 2005/07/13 18:01:39 jlam Exp $
#

DISTNAME=	Digest-MD5-2.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5md5
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-MD5/
COMMENT=	Perl5 extension interface for MD5 algorithm

DEPENDS+=	p5-Digest>=1.00:../p5-Digest

CONFLICTS+=	p5-MD5-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Digest/MD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
