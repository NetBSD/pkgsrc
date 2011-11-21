# $NetBSD: Makefile,v 1.6 2011/11/21 06:14:39 hiramatsu Exp $

DISTNAME=	Object-Signature-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-Signature/
COMMENT=	Generate cryptographic signatures for objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Storable>=2.11:../../devel/p5-Storable
DEPENDS+=	p5-Digest-MD5>=2.00:../../security/p5-Digest-MD5
DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple
DEPENDS+=	p5-PathTools>=0.80:../../devel/p5-PathTools
DEPENDS+=	p5-ExtUtils-AutoInstall>=0.63:../../devel/p5-ExtUtils-AutoInstall

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/Signature/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
