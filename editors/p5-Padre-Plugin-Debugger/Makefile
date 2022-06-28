# $NetBSD: Makefile,v 1.18 2022/06/28 11:33:47 wiz Exp $
#

VERSION=	0.3
PKGNAME=	p5-Padre-Plugin-Debugger-${VERSION}
GITHUB_PROJECT=	${PKGBASE:S/p5-//:tl}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	13
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=pmakholm/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pmakholm/padre-plugin-debugger/
COMMENT=	Debug Perl code from Padre editor
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-ebug>=0.49:../../devel/p5-Devel-ebug
DEPENDS+=	p5-Padre>=0.28:../../editors/p5-Padre
#DEPENDS+=	{perl>=5.10.1,parent-[0-9]*}:../../devel/p5-parent

PERL5_PACKLIST=		auto/Padre/Plugin/Debugger/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
