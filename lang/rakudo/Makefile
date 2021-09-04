# $NetBSD: Makefile,v 1.20 2021/09/04 11:32:21 mef Exp $

DISTNAME=	rakudo-2021.08
CATEGORIES=	lang perl6
MASTER_SITES=	https://rakudo.org/dl/rakudo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
COMMENT=	Perl 6 reference implementation
LICENSE=	artistic-2.0

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake

TEST_TARGET=		test

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX} --backends=moar

REPLACE_INTERPRETER+=	raku
REPLACE.raku.old=	/usr/bin/env raku
REPLACE.raku.new=	${PREFIX}/bin/raku
REPLACE_FILES.raku=	tools/install-dist.p6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	EXT=dylib
.else
PLIST_SUBST+=	EXT=so
.endif

INSTALLATION_DIRS=	share/perl6/bin

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/core/precomp/*
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/precomp/*
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install-dist.p6 ${DESTDIR}${PREFIX}/share/perl6/bin/


.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
