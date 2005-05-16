# $NetBSD: Makefile,v 1.9 2005/05/16 01:15:31 jlam Exp $
#

DISTNAME=	chkfontpath-1.9.7
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/linux/9/en/os/i386/SRPMS/
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Command line tool to manage X server's font path

BUILD_DEPENDS+=	rpm2cpio>=1.1:../../converters/rpm2cpio

MAKE_ENV+=	VERSION=${PKGVERSION}
USE_GNU_TOOLS+=	make

PKGSRC_USE_TOOLS+=	gtar

# Might as well make this a general scheme for .src.rpm files... - HF
do-extract:
		cd ${WRKDIR} ; \
		${PREFIX}/bin/rpm2cpio.pl ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		| ${PAX} -r ; \
		${GTAR} zxf ${DISTNAME}.tar.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/chkfontpath ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/man/en/chkfontpath.8 ${PREFIX}/man/man8

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
