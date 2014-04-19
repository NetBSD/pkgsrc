# $NetBSD: Makefile,v 1.92.2.1 2014/04/19 05:19:38 spz Exp $

DISTNAME=	rsync-3.1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/doc/rsync

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-popt
CONFIGURE_ARGS+=	--with-rsyncd-conf=${PKG_SYSCONFDIR}/rsyncd.conf
TEST_TARGET=		test

PKG_SYSCONFSUBDIR=	rsync

RCD_SCRIPTS=		rsyncd
RCD_SCRIPT_SRC.rsyncd=	files/rsyncd.sh
SMF_NAME=		rsyncd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/tech_report.tex \
		${DESTDIR}${PREFIX}/share/doc/rsync

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
