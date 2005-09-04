# $NetBSD: Makefile,v 1.23 2005/09/04 17:09:54 sjg Exp $
#

DISTNAME=       bmake-20050901
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	mk-files>=20030714:../../devel/mk-files

WRKSRC=		${WRKDIR}/bmake

makesyspath=${PREFIX}/share/mk:/usr/share/mk:/usr/local/share/mk:/opt/share/mk
GNU_CONFIGURE=	no
CONFIGURE_ARGS+= --with-default-sys-path=${makesyspath}

INSTALLATION_DIRS=	bin man/cat1 man/man1

do-configure:

do-build:
	cd ${WRKDIR} && ./bmake/boot-strap -q -o ${OPSYS} ${CONFIGURE_ARGS}

# we use locally formatted version if available
BMAKE_CATg=${WRKDIR}/${OPSYS}/bmake.cat1
# otherwise we use the distributed one
BMAKE_CATd=${WRKSRC}/bmake.cat1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${BMAKE_CAT1} ${PREFIX}/man/cat1/bmake.0
	${INSTALL_MAN} ${WRKDIR}/${OPSYS}/bmake.1 ${PREFIX}/man/man1

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
