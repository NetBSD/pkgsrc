# $NetBSD: Makefile,v 1.12 2003/09/18 18:34:28 jmmv Exp $
#

DISTNAME=	mldonkey-${VER}.sources
VER=		2.5-3
PKGNAME=	mldonkey-${VER:S/-/./}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/mldonkey-${VER}
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/release-${VER}/official/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/mldonkey/
COMMENT=	Free peer-to-peer client with eDonkey support and more

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		build

MLDONKEY_SUBST=		PREFIX="${PREFIX}"
MLDONKEY_SUBST_SED=	${MLDONKEY_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

CONFIGURE_ENV+=		WGET=""
CONFIGURE_ENV+=		ac_cv_prog_WGET="no"
MAKE_ENV+=		BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread}
CONFIGURE_ARGS+=	--enable-pthread-lib

pre-build:
	${SED} ${MLDONKEY_SUBST_SED} ${FILESDIR}/mldonkey.sh > \
	    ${WRKDIR}/mldonkey.sh
	${CHMOD} +x ${WRKDIR}/mldonkey.sh

do-install:
	( cd ${WRKDIR} && \
	    ${INSTALL_SCRIPT} mldonkey.sh ${PREFIX}/bin/mldonkey \
	)
	( cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlchat ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlguistarter ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlgui ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlim ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlnet ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlnet+gui ${PREFIX}/libexec/mldonkey \
	)

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"
.include "../../x11/lablgtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
