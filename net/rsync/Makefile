# $NetBSD: Makefile,v 1.33 2001/01/28 13:44:16 tron Exp $

DISTNAME=	rsync-2.4.6
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://rsync.samba.org/

GNU_CONFIGURE=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://ftp.pasta.cs.uit.no/pub/IPv6/misc/
PATCHFILES=	rsync-246-v6-20000907.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS=	--enable-ipv6
.else
CONFIGURE_ARGS=	--disable-ipv6
.endif

post-install:
	@strip ${PREFIX}/bin/rsync
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync

.include "../../mk/bsd.pkg.mk"
