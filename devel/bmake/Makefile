# $NetBSD: Makefile,v 1.80 2022/11/09 13:14:07 joerg Exp $

DISTNAME=	bmake-20200524
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	pkgsrc-users@NetBSD.org
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
CONFIGURE_ARGS+=	--with-machine_arch=${MACHINE_ARCH}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

#
# This section is incomplete, but the general idea is that we should use the
# same shell that was selected by bootstrap.
#
.if ${TOOLS_PLATFORM.sh:M?*/bin/mksh}
DEPENDS+=		mksh-[0-9]*:../../shells/mksh
CONFIGURE_ARGS+=	--with-defshell=${PREFIX}/bin/mksh
.elif ${TOOLS_PLATFORM.sh:M?*/bin/pdksh}
DEPENDS+=		pdksh-[0-9]*:../../shells/pdksh
CONFIGURE_ARGS+=	--with-defshell=${PREFIX}/bin/pdksh
.elif ${OPSYS} == "SunOS" && exists(/usr/bin/bash)
CONFIGURE_ARGS+=	--with-defshell=/usr/bin/bash
.endif

MAKE_ENV.Interix+=	XDEFS=-DUSE_SELECT

# Fix bmake not finding files (e.g. .include) on Illumos with 32 bit ABI
CFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SH} make-bootstrap.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmake ${DESTDIR}${PREFIX}/bin
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/bmake.1
.  else
	${INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/bmake.0
.  endif
.endif
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC}/unit-tests && ${WRKSRC}/bmake test

.include "../../mk/bsd.pkg.mk"
