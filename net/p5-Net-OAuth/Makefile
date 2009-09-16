# $NetBSD: Makefile,v 1.1.1.1 2009/09/16 19:40:03 sno Exp $
#

DISTNAME=	Net-OAuth-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-OAuth/
COMMENT=	Perl5 extension for OAuth protocol support
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor>=0.31:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.06:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI>=1.31:../../www/p5-URI

PERL5_PACKLIST=		auto/Net/OAuth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
