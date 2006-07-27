# $NetBSD: Makefile,v 1.30 2006/07/27 23:45:08 kristerw Exp $

DISTNAME=	ghc-6.4.2
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.4.2/
DISTFILES=	ghc-6.4.2-src.tar.bz2 \
		ghc-6.2.1-src.tar.bz2 \
		ghc-6.2.1-i386-unknown-netbsd-hc.tar.gz

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell

SITES.ghc-6.2.1-i386-unknown-netbsd-hc.tar.gz=${MASTER_SITE_LOCAL}
SITES.ghc-6.2.1-src.tar.bz2=http://www.haskell.org/ghc/dist/6.2.1/

ONLY_FOR_PLATFORM= NetBSD-1.5*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ghc=${WRKDIR}/bootstrap/bin/ghc
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
USE_GNU_READLINE=	yes	# uses the UNDO_ constants
USE_TOOLS+=		gmake perl:run

pre-configure:
	${MV} ${WRKDIR}/ghc-6.2.1/mk/bootstrap.mk \
		${WRKDIR}/ghc-6.2.1/mk/bootstrap.mk.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKDIR}/ghc-6.2.1/mk/bootstrap.mk.tmp \
		> ${WRKDIR}/ghc-6.2.1/mk/bootstrap.mk
	${MV} ${WRKDIR}/ghc-6.2.1/libraries/readline/package.conf.in \
		${WRKDIR}/ghc-6.2.1/libraries/readline/package.conf.in.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKDIR}/ghc-6.2.1/libraries/readline/package.conf.in.tmp \
		> ${WRKDIR}/ghc-6.2.1/libraries/readline/package.conf.in
	${MV} ${WRKDIR}/ghc-6.2.1/ghc/rts/package.conf.in \
		${WRKDIR}/ghc-6.2.1/ghc/rts/package.conf.in.tmp
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKDIR}/ghc-6.2.1/ghc/rts/package.conf.in.tmp \
		> ${WRKDIR}/ghc-6.2.1/ghc/rts/package.conf.in
	cd ${WRKDIR}/ghc-6.2.1 && \
		./distrib/hc-build \
			--enable-hc-boot-unregisterised \
			--prefix=${WRKDIR}/bootstrap
	cd ${WRKDIR}/ghc-6.2.1 && ${GMAKE} stage=1 install

pre-build:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
