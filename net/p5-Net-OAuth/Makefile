# $NetBSD: Makefile,v 1.3 2010/03/16 18:23:14 sno Exp $
#

DISTNAME=	Net-OAuth-0.22
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
DEPENDS+=	p5-Digest-SHA1>=2.12:../../security/p5-Digest-SHA1
DEPENDS+=	{perl>=5.10.1,p5-Encode>=2.35}:../../textproc/p5-Encode
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI

PERL5_PACKLIST=		auto/Net/OAuth/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
