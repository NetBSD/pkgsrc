# $NetBSD: Makefile,v 1.16 2020/03/14 11:13:20 mef Exp $
#

DISTNAME=	cc65-2.18
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	cross lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cc65/}
GITHUB_PROJECT=	cc65
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cc65.github.io/
COMMENT=	C cross compiler for 6502 target systems
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake perl
REPLACE_PERL=	util/ca65html

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	src/ca65/macpack/cvt-mac.pl src/ld65/cfg/cvt-cfg.pl
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

.include "../../mk/bsd.pkg.mk"
