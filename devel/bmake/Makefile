# $NetBSD: Makefile,v 1.39 2008/02/05 15:37:18 tnn Exp $
#

DISTNAME=	bmake-20051105
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	bootstrap-mk-files-[0-9]*:../../pkgtools/bootstrap-mk-files

WRKSRC=		${WRKDIR}/bmake
NO_CHECKSUM=	yes
NO_MTREE=	yes

USE_FEATURES=	nbcompat

makesyspath=	${PREFIX}/share/mk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BOOTSTRAP_ARGS=		-q -o ${OPSYS} --prefix=${PREFIX} \
			--with-default-sys-path=${makesyspath} \
			--mksrc none --sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && exists(/usr/xpg4/bin/sh)
BOOTSTRAP_ARGS+=	--with-defshell=/usr/xpg4/bin/sh
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:

do-build:
	cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} ${SH} ./bmake/boot-strap ${BOOTSTRAP_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
