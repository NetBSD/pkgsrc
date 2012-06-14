# $NetBSD: Makefile,v 1.20 2012/06/14 09:59:12 jperkin Exp $
#

DISTNAME=	chkfontpath-1.9.7
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/linux/9/en/os/i386/SRPMS/
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line tool to manage X server's font path

BUILD_DEPENDS+=	rpm2cpio>=1.1:../../converters/rpm2cpio

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	VERSION=${PKGVERSION:Q}
USE_TOOLS+=	gmake gtar pax

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"

# Native Solaris pax cannot handle cpio archives produced by rpm2cpio.pl, cpio
# can but it is not a tool.
.if ${OPSYS} == "SunOS"
TOOLS_PLATFORM.pax=
.endif

# Might as well make this a general scheme for .src.rpm files... - HF
do-extract:
		cd ${WRKDIR} ; \
		${PREFIX}/bin/rpm2cpio.pl ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		| pax -r ; \
		${GTAR} zxf ${DISTNAME}.tar.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/chkfontpath ${DESTDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/man/en/chkfontpath.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
