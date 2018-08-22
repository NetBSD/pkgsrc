# $NetBSD: Makefile,v 1.3 2018/08/22 09:45:22 wiz Exp $

DISTNAME=	rakudo-2017.09
PKGREVISION=	2
CATEGORIES=	lang perl6
MASTER_SITES=	http://rakudo.org/downloads/rakudo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rakudo.org/
COMMENT=	Perl 6 reference implementation
LICENSE=	artistic-2.0

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake

TEST_TARGET=		test

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} --backends=moar

SUBST_CLASSES+=		interp
SUBST_STAGE.interp=	pre-configure
SUBST_MESSAGE.interp=	Fixing interpreter line.
SUBST_FILES.interp=	src/core/CompUnit/Repository/Installation.pm
SUBST_FILES.interp+=	tools/install-dist.pl
SUBST_SED.interp=	-e 's,/usr/bin/env ,${PREFIX}/bin/,'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	EXT=dylib
.else
PLIST_SUBST+=	EXT=so
.endif

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/precomp/*
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install-dist.pl ${DESTDIR}${PREFIX}/share/perl6/bin

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
