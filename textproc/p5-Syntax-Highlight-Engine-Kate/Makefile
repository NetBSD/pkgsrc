# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:09 obache Exp $
#

DISTNAME=	Syntax-Highlight-Engine-Kate-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Syntax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Syntax-Highlight-Engine-Kate/
COMMENT=	Perl port of the syntax highlight engine of the Kate texteditor
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP=	samples/highlight.sh

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Syntax/Highlight/Engine/Kate/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
