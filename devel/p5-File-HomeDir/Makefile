# $NetBSD: Makefile,v 1.16 2011/08/13 07:54:44 adam Exp $

DISTNAME=	File-HomeDir-0.98
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-HomeDir/
COMMENT=	Get the home directory for yourself or other users
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/File/HomeDir/.packlist

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which
.if ${OPSYS} == "Darwin"
DEPENDS+=		p5-Mac-SystemDirectory>=0.04:../../devel/p5-Mac-SystemDirectory
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
