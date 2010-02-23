# $NetBSD: Makefile,v 1.6 2010/02/23 14:12:18 sno Exp $
#

DISTNAME=	File-ChangeNotify-0.12
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ChangeNotify/
COMMENT=	Watch for changes to files, cross-platform style
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-MOP-[0-9]*:../../devel/p5-Class-MOP
DEPENDS+=	{perl>=5.10,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Params-Validate>=0.08:../../devel/p5-MooseX-Params-Validate
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor
DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/ChangeNotify/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
DEPENDS+=	p5-IO-KQueue-[0-9]*:../../sysutils/p5-IO-KQueue
.elif ${OPSYS} == "Linux"
DEPENDS+=	p5-Linux-Inotify2>=1.2:../../sysutils/p5-Linux-Inotify2
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
