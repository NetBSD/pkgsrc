# $NetBSD: Makefile,v 1.27 2005/11/10 00:09:34 reed Exp $
#

DISTNAME=       bmake-20051105
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

WRKSRC=		${WRKDIR}/bmake
NO_CHECKSUM=	YES

makesyspath=${PREFIX}/share/mk:/usr/share/mk:/usr/local/share/mk:/opt/share/mk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:

do-build:
	cd ${WRKDIR} && \
		./bmake/boot-strap -q -o ${OPSYS} --prefix=${PREFIX} \
		--with-default-sys-path=${makesyspath} --mksrc none \
		--sysconfdir=${PKG_SYSCONFDIR}

# we use locally formatted version if available
BMAKE_CATg=${WRKDIR}/${OPSYS}/bmake.cat1
# otherwise we use the distributed one
BMAKE_CATd=${WRKSRC}/bmake.cat1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${BMAKE_CAT1} ${PREFIX}/${PKGMANDIR}/cat1/bmake.0
	${INSTALL_MAN} ${WRKDIR}/${OPSYS}/bmake.1 ${PREFIX}/${PKGMANDIR}/man1

.if defined(LIBNBCOMPAT_STYLE) && (${LIBNBCOMPAT_STYLE} == "inplace")  
.  include "../../pkgtools/libnbcompat/inplace.mk"
.else
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"

# with bmake-20040108 or later we could use
# ${exists(${BMAKE_CATg}):?${BMAKE_CATg}:${BMAKE_CATd}}
# to do the existence test at the time we run the script
# but pkgsrc/bootstrap/bmake won't handle that.
.if exists(${BMAKE_CATg})
BMAKE_CAT1=${BMAKE_CATg}
.else
BMAKE_CAT1=${BMAKE_CATd}
.endif
