# $NetBSD: Makefile,v 1.1.1.1 2003/03/31 15:56:01 jmmv Exp $
#

DISTNAME=	mldonkey-2.04rc1.sources
PKGNAME=	${DISTNAME:S/.sources//}
WRKSRC=		${WRKDIR}/mldonkey
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/release-2.04rc1/

MAINTAINER=	packages@netbsd.org
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
CONFIGURE_ARGS+=	--enable-pthread-lib
CONFIGURE_ARGS+=	--disable-multinet

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
	    ${INSTALL_PROGRAM} mldonkey ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mldonkey_gui ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mldonkey_gui2 ${PREFIX}/libexec/mldonkey && \
	    ${INSTALL_PROGRAM} mldonkey_guistarter ${PREFIX}/libexec/mldonkey \
	)

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"
.include "../../x11/lablgtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
