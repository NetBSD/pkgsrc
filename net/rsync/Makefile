# $NetBSD: Makefile,v 1.21 1999/07/08 17:29:24 itojun Exp $
#

DISTNAME=	rsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6)
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	rsync-231-v6-19990520.diff.gz
PATCH_DIST_STRIP=	-p1
PATCHDIR=	${.CURDIR}/patches.v6
.else
# always fetch IPv6 patch, for files/md5
MASTER_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		rsync-231-v6-19990520.diff.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=     mycroft@netbsd.org
HOMEPAGE=	http://samba.anu.edu.au/rsync/

GNU_CONFIGURE=	yes

post-install:
	@strip ${PREFIX}/bin/rsync
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync

.include "../../mk/bsd.pkg.mk"
