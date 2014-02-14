# $NetBSD: Makefile,v 1.64 2014/02/14 16:09:18 jperkin Exp $

DISTNAME=	bmake-20140214
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility
LICENSE=	modified-bsd

DEPENDS+=	bootstrap-mk-files-[0-9]*:../../pkgtools/bootstrap-mk-files

BOOTSTRAP_PKG=	yes

WRKSRC=		${WRKDIR}/bmake

USE_FEATURES=	nbcompat

makesyspath=	${PREFIX}/share/mk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-default-sys-path=${makesyspath}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-*) && exists(/usr/bin/bash)
CONFIGURE_ARGS+=	--with-defshell=/usr/bin/bash
.elif ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "IRIX"
DEPENDS+=		pdksh-[0-9]*:../../shells/pdksh
CONFIGURE_ARGS+=	--with-defshell=${PREFIX}/bin/pdksh
.endif
.if ${OPSYS} == "Interix"
MAKE_ENV+=		XDEFS=-DUSE_SELECT
.endif
.if ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	--with-machine_arch=${MACHINE_ARCH}
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SH} make-bootstrap.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmake ${DESTDIR}${PREFIX}/bin
.if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/bmake.1
.else
	${INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/bmake.0
.endif
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC}/unit-tests && ${WRKSRC}/bmake test

.include "../../mk/bsd.pkg.mk"
