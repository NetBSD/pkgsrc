# $NetBSD: Makefile,v 1.70 2008/03/09 20:56:57 bjs Exp $

DISTNAME=	rsync-3.0.0
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
TEST_TARGET=		test
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-included-popt
CONFIGURE_ARGS+=	--with-rsyncd-conf=${${PKG_SYSCONFDIR}/rsyncd.conf:L:Q}
CONFIGURE_SCRIPT=	configure.sh

CONF_FILES=		${EGDIR}/rsyncd.conf ${PKG_SYSCONFDIR}/rsyncd.conf
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	rsync

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	${WRKDIR}/rsyncd.conf rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'
SUBST_VARS.paths=	VARBASE

.PHONY: install-examples
install-examples:
	${RUN} \
	    ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR} && \
	    ${INSTALL_DATA} ${WRKDIR}/rsyncd.conf  ${DESTDIR}${EGDIR}
post-extract:
	${RUN} \
	    ${CP} ${FILESDIR}/rsyncd.conf ${WRKDIR}
post-install: install-examples
	${RUN} \
	    ${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE} && \
	    ${INSTALL_DATA} ${WRKSRC}/tech_report.tex \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE} && \
	    ${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
