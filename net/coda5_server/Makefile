# $NetBSD: Makefile,v 1.28 2001/05/31 22:58:08 jlam Exp $
#

DISTNAME=		coda-5.3.13
PKGNAME=		coda-server-5.3.13
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/
COMMENT=		server programs for a replicated high-performance network file system

# Only enable platforms that can build "lwp".
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../devel/lwp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../devel/rpc2/buildlink.mk"
.include "../../devel/rvm/buildlink.mk"

CFLAGS+=		-I${BUILDLINK_INCDIR}
CXXFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

INSTALL_SUBST=		CAT=${CAT}
INSTALL_SUBST+=		LN=${LN}
INSTALL_SUBST+=		RM=${RM}
INSTALL_SUBST+=		RMDIR=${RMDIR}
INSTALL_SUBST+=		TRUE=${TRUE}

pre-configure: ${BUILDLINK_TARGETS}

pre-install:
	${SED} ${INSTALL_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}		\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${INSTALL_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}		\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
