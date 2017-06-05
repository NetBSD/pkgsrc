# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:56 ryoon Exp $
#

DISTNAME=	Padre-Plugin-Debugger-0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Debugger/
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
