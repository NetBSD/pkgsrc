# $NetBSD: Makefile,v 1.7 2012/07/06 10:49:51 sno Exp $

DISTNAME=	Git-CPAN-Patch-0.8.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-CPAN-Patch/
COMMENT=	Patch CPAN modules using Git
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-BackPAN-Index>=0.39:../../devel/p5-BackPAN-Index
DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-DateTime-Format-W3CDTF-[0-9]*:../../time/p5-DateTime-Format-W3CDTF
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-chmod-[0-9]*:../../sysutils/p5-File-chmod
DEPENDS+=	p5-Git-Repository-[0-9]*:../../devel/p5-Git-Repository
DEPENDS+=	p5-MetaCPAN-API-[0-9]*:../../devel/p5-MetaCPAN-API
DEPENDS+=	p5-Method-Signatures-[0-9]*:../../devel/p5-Method-Signatures
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-App-Cmd-[0-9]*:../../devel/p5-MooseX-App-Cmd
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor
DEPENDS+=	{perl>=5.10.1,p5-autodie-[0-9]*}:../../devel/p5-autodie
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww # LWP::UserAgent

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/CPAN/Patch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
