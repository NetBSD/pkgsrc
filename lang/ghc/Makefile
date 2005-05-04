# $NetBSD: Makefile,v 1.21 2005/05/04 19:02:33 kristerw Exp $

DISTNAME=	ghc-6.2.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.2.1/
DISTFILES=	ghc-6.2.1-src.tar.bz2 \
		ghc-6.2.1-i386-unknown-netbsd-hc.tar.gz

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell

SITES_ghc-6.2.1-i386-unknown-netbsd-hc.tar.gz=${MASTER_SITE_LOCAL}

ONLY_FOR_PLATFORM= NetBSD-1.5*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./distrib/hc-build
CONFIGURE_ARGS+=	--enable-hc-boot-unregisterised
INSTALL_MAKE_FLAGS+=	stage=1


USE_GNU_READLINE=	yes	# uses the UNDO_ constants
USE_PERL5=		yes
USE_GNU_TOOLS+=		make

# Everything is done in the configure target.
do-build:
	@${DO_NADA}

pre-configure:
	${MV} ${WRKSRC}/mk/bootstrap.mk ${WRKSRC}/mk/bootstrap.mk.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKSRC}/mk/bootstrap.mk.tmp \
		> ${WRKSRC}/mk/bootstrap.mk
	${MV} ${WRKSRC}/libraries/readline/package.conf.in \
		${WRKSRC}/libraries/readline/package.conf.in.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKSRC}/libraries/readline/package.conf.in.tmp \
		> ${WRKSRC}/libraries/readline/package.conf.in
	${MV} ${WRKSRC}/ghc/rts/package.conf.in \
		${WRKSRC}/ghc/rts/package.conf.in.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKSRC}/ghc/rts/package.conf.in.tmp \
		> ${WRKSRC}/ghc/rts/package.conf.in

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
