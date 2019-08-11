# $NetBSD: Makefile,v 1.111 2019/08/11 13:22:29 wiz Exp $

DISTNAME=	rsync-3.1.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/
MASTER_SITES+=	http://rsync.samba.org/ftp/rsync/old-versions/
MASTER_SITES+=	ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/doc/rsync

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-popt
CONFIGURE_ARGS+=	--with-rsyncd-conf=${PKG_SYSCONFDIR}/rsyncd.conf
TEST_TARGET=		test

USE_TOOLS+=	perl

PKG_SYSCONFSUBDIR=	rsync

RCD_SCRIPTS=		rsyncd
RCD_SCRIPT_SRC.rsyncd=	files/rsyncd.sh
SMF_NAME=		rsyncd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/tech_report.tex \
		${DESTDIR}${PREFIX}/share/doc/rsync

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
