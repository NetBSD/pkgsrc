# $NetBSD: Makefile,v 1.33 2024/03/09 07:04:37 mef Exp $

DISTNAME=	rakudo-2024.02
CATEGORIES=	lang perl6
MASTER_SITES=	${MASTER_SITE_GITHUB:=rakudo/}

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

#do-configure:
#	(cd ${WRKSRC} ; \
#	perl Configure.pl                      --backends=moar --prefix=$HOME/raku ; \
#	)
#	perl Configure.pl --gen-moar --gen-nqp --backends=moar --prefix=$HOME/raku ;

# gmake: *** No rule to make target '3rdparty/nqp-configure/lib/NQP/Config.pm', needed by 'gen/moar/main-version.nqp'.  Stop.
# hard coding should be corrected ..
pre-build:
	${MKDIR} -p  ${WRKSRC}/3rdparty/nqp-configure/lib/NQP
	cp -p ${PREFIX}/lib/perl5/site_perl/5.38.0/NQP/Config.pm ${WRKSRC}/3rdparty/nqp-configure/lib/NQP/
	cp -p ${PREFIX}/lib/perl5/site_perl/5.38.0/NQP/Macros.pm ${WRKSRC}/3rdparty/nqp-configure/lib/NQP/


post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/core/precomp/*
	${RM} -rf ${DESTDIR}${PREFIX}/share/perl6/precomp/*
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install-dist.p6 ${DESTDIR}${PREFIX}/share/perl6/bin/
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/core/short/38673F0433DE95B90DD16424ED7B5B6520D383C5/E14CAA5C7DE5B1A1BAC1ED1155377A9AF4962C18
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/core/sources/85FD80E5C2ED76D28F0A55D85C2F3F0EC168B638

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
