# $NetBSD: Makefile,v 1.13 2018/02/21 15:20:04 triaxx Exp $
#

DISTNAME=	3proxy-0.8.11
CATEGORIES=	net
MASTER_SITES=	https://3proxy.ru/${DISTNAME:S/3proxy-//}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://3proxy.ru/
COMMENT=	Multi-protocol proxy
# 3proxy-0.5.* is dual-licenced under GPL or custom terms.  It's not
# clear exactly which version of the GPL is intended; ${WRKSRC}/License
# says "current version of GNU GPL" without specifying a numeric version
# number.  3proxy-0.6.* will have a different license.
# 3proxy-0.7-license is now inspired by BSD license.
LICENSE=	3proxy-0.7-license

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
REQD_FILES=		${EGDIR}/3proxy.cfg.sample \
			${PKG_SYSCONFDIR}/${PKGBASE}/3proxy.cfg
OWN_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE} ${VARBASE}/log/${PKGBASE}
RCD_SCRIPTS=		threeproxy
WRKSRC=			${WRKDIR}/${PKGBASE}
MAKE_FILE=		Makefile.unix
MAKE_FLAGS+=		LIBS=${BUILDLINK_LDADD.dl:Q}

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR}

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-install
SUBST_MESSAGE.cfg=	Adjusting config sample file.
SUBST_FILES.cfg=	cfg/3proxy.cfg.sample man/3proxy.8 man/3proxy.cfg.3
SUBST_VARS.cfg+=	PREFIX
SUBST_VARS.cfg+=	PKG_SYSCONFDIR
SUBST_VARS.cfg+=	VARBASE

# We install only 3proxy and its man pages.  There are several other
# binaries which we don't install, because the 3proxy executable
# provides a superset of the functionality of the others.  We also don't
# install the HTML pages, because they provide no more information than
# the man pages.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/3proxy ${DESTDIR}${PREFIX}/sbin/.
	${INSTALL_MAN} ${WRKSRC}/man/3proxy.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/.
	${INSTALL_MAN} ${WRKSRC}/man/3proxy.cfg.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/3proxy.cfg.5
	${INSTALL_DATA} ${WRKSRC}/cfg/3proxy.cfg.sample \
		${DESTDIR}${EGDIR}/3proxy.cfg.sample

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
