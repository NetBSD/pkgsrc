# $NetBSD: Makefile,v 1.6 2019/08/11 13:21:23 wiz Exp $

DISTNAME=	rakudo-2018.12
PKGREVISION=	1
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
CONFIGURE_ARGS=		--prefix=${PREFIX} --backends=moar

REPLACE_PERL6=		tools/install-dist.p6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	EXT=dylib
.else
PLIST_SUBST+=	EXT=so
.endif

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/precomp/*
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install-dist.p6 ${DESTDIR}${PREFIX}/share/perl6/bin

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
