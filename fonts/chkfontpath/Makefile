# $NetBSD: Makefile,v 1.23 2012/10/03 18:28:17 asau Exp $
#

DISTNAME=	chkfontpath-1.9.7
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/linux/9/en/os/i386/SRPMS/
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line tool to manage X server's font path
LICENSE=	gnu-gpl-v2 # or later

MAKE_ENV+=	VERSION=${PKGVERSION:Q}
USE_TOOLS+=	gmake tar gzcat

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

post-extract:
		${RUN}cd ${WRKDIR};${EXTRACTOR} ${DISTNAME}.tar.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/chkfontpath ${DESTDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/man/en/chkfontpath.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
