# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:46 cheusov Exp $

DISTNAME=	gnats-3.113.1
PKGNAME=	send-pr-${GNATS_VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=gnats/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS problem reporting tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gnats-${GNATS_VERSION}/send-pr
GNATS_VERSION=	${DISTNAME:S/gnats-//}

CONFLICTS+=	gnats-[0-9]* arla-[0-9]*

GNU_CONFIGURE=		YES
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
INFO_FILES=		yes

LISPDIR=		${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS=		--with-lispdir=${LISPDIR}

CONFIGURE_ENV+=		GNATS_ROOT=${PKG_SYSCONFDIR}/gnats

INSTALL_TARGET=		install install-info

# this stops the configuration program from pulling installation
# information in from the standard NetBSD send-pr program
CONFIGURE_ENV+=		SEND_PR=/dev/null

BUILD_MAKE_FLAGS+=	MAKEINFO=makeinfo\ --no-split
INSTALL_MAKE_FLAGS+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} \
			man1dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \
			bindir=${DESTDIR}${PREFIX}/bin \
			datadir=${DESTDIR}${PREFIX}/share \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			lispdir=${DESTDIR}${LISPDIR}

AUTO_MKDIRS=		yes

EGDIR=			${PREFIX}/share/examples/gnats
CONF_FILES=		${EGDIR}/config \
			${PKG_SYSCONFDIR}/gnats/gnats-adm/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/gnats \
			${PKG_SYSCONFDIR}/gnats/gnats-adm

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-patch
SUBST_MESSAGE.fix-paths=Fixing paths
SUBST_FILES.fix-paths=	send-pr.sh
SUBST_SED.fix-paths=	-e 's,install-sid,${PREFIX}/bin/install-sid,'
SUBST_SED.fix-paths+=	-e 's,send-pr --request-id,${PREFIX}/bin/send-pr --request-id,'

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/gnats/dist/INSTALL.send-pr
	${INSTALL_DATA} ${FILESDIR}/netbsd-categories ${DESTDIR}${PREFIX}/share/gnats/netbsd
	${INSTALL_DATA} ${FILESDIR}/config ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
