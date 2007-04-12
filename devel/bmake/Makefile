# $NetBSD: Makefile,v 1.35 2007/04/12 21:28:42 joerg Exp $
#

DISTNAME=	bmake-20051105
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	bootstrap-mk-files-[0-9]*:../../pkgtools/bootstrap-mk-files

WRKSRC=		${WRKDIR}/bmake
NO_CHECKSUM=	yes
NO_MTREE=	yes

makesyspath=	${PREFIX}/share/mk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:

do-build:
	cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} ${SH} ./bmake/boot-strap \
		-q -o ${OPSYS} --prefix=${PREFIX} \
		--with-default-sys-path=${makesyspath} --mksrc none \
		--sysconfdir=${PKG_SYSCONFDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"
