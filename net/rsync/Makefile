# $NetBSD: Makefile,v 1.25 1999/09/03 22:00:52 tron Exp $
#

DISTNAME=	rsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://ftp.pasta.cs.uit.no/pub/IPv6/misc/
PATCHFILES=	rsync-231-v6-19990723.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=     mycroft@netbsd.org
HOMEPAGE=	http://samba.anu.edu.au/rsync/

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
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
