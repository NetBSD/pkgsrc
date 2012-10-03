# $NetBSD: Makefile,v 1.5 2012/10/03 21:55:49 wiz Exp $
#

DISTNAME=	UUID-Tiny-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UUID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UUID-Tiny/
COMMENT=	Pure Perl UUID Support With Functional Interface
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/UUID/Tiny/.packlist

DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
