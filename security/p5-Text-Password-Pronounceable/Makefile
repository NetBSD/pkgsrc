# $NetBSD: Makefile,v 1.5 2012/09/03 11:16:23 sno Exp $

DISTNAME=	Text-Password-Pronounceable-0.30
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	perl5 textproc security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Password-Pronounceable/
COMMENT=	Generate pronounceable passwords
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Password/Pronounceable/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
