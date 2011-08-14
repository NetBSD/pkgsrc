# $NetBSD: Makefile,v 1.23 2011/08/14 12:26:26 obache Exp $
#

DISTNAME=	PAR-Dist-0.47
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5moi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PAR-Dist/
COMMENT=	Perl module toolkit to create and manipulate PAR distributions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip>1.28:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Module-Signature>=0.25:../../security/p5-Module-Signature
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PAR/Dist/.packlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-PAR-Dist
PKG_SUPPORTED_OPTIONS+=	# empty
PKG_SUGGESTED_OPTIONS+=	# empty

PKG_OPTIONS_REQUIRED_GROUPS=	YAML
PKG_OPTIONS_GROUP.YAML=		YAML LibYAML YAML-Tiny
PKG_SUGGESTED_OPTIONS=		LibYAML

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MYAML-Tiny)
BUILD_DEPENDS+=	p5-YAML-Tiny>=1.25:../../textproc/p5-YAML-Tiny
.elif !empty(PKG_OPTIONS:MLibYAML)
BUILD_DEPENDS+=	p5-YAML-LibYAML>=0.03:../../textproc/p5-YAML-LibYAML
.elif !empty(PKG_OPTIONS:MYAML)
BUILD_DEPENDS+=	p5-YAML>=0.60:../../textproc/p5-YAML
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
