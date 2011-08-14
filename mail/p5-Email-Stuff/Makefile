# $NetBSD: Makefile,v 1.7 2011/08/14 13:25:24 obache Exp $

DISTNAME=	Email-Stuff-2.102
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Stuff/
COMMENT=	More casual approach to creating and sending emails
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Send>=2.185:../../mail/p5-Email-Send
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-File-Type>=0.22:../../devel/p5-File-Type
DEPENDS+=	p5-Params-Util>=0.23:../../devel/p5-Params-Util
DEPENDS+=	p5-prefork>=1.01:../../devel/p5-prefork
# BUILD_DEPENDS+= Email-Send-Test

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Email/Stuff/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
