# $NetBSD: Makefile,v 1.23 2004/10/03 00:17:55 tv Exp $
#

DISTNAME=	mldonkey-2.5.21
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/mldonkey/
COMMENT=	Free peer-to-peer client with eDonkey support and more

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

MLDONKEY_SUBST=		PREFIX="${PREFIX}"
MLDONKEY_SUBST_SED=	${MLDONKEY_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

CONFIGURE_ENV+=		WGET=""
CONFIGURE_ENV+=		ac_cv_prog_WGET="no"
MAKE_ENV+=		BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread}
CONFIGURE_ARGS+=	--enable-pthread-lib

UNLIMIT_RESOURCES=	stacksize

pre-build:
	${SED} ${MLDONKEY_SUBST_SED} ${FILESDIR}/mldonkey.sh > \
	    ${WRKDIR}/mldonkey.sh
	${CHMOD} +x ${WRKDIR}/mldonkey.sh

do-install:
	cd ${WRKDIR} && \
	    ${INSTALL_SCRIPT} mldonkey.sh ${PREFIX}/bin/mldonkey
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlchat ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlguistarter ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlgui ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlim ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlnet ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mlnet+gui ${PREFIX}/libexec/mldonkey

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
