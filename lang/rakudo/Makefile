# $NetBSD: Makefile,v 1.23 2022/01/23 23:54:20 mef Exp $

DISTNAME=	rakudo-2021.12
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
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/core/short/38673F0433DE95B90DD16424ED7B5B6520D383C5/E14CAA5C7DE5B1A1BAC1ED1155377A9AF4962C18
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/core/sources/85FD80E5C2ED76D28F0A55D85C2F3F0EC168B638

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
