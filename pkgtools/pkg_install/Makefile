# $NetBSD: Makefile,v 1.84 2003/09/14 15:29:03 jlam Exp $

# Notes to package maintainers:
#
# To update this package, import from src/usr.sbin/pkg_install.
#
# Updating this package does not automatically necessitate bumping
# PKGTOOLS_REQD in bsd.pkg.mk. Do so if and only if there is a critical
# change in the pkg_* tools that pkgsrc relies on for proper operation.

DISTNAME=		pkg_install-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Package installation and administration tools

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_BUILDLINK=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted
PKG_PRESERVE=		# defined

LIBNBCOMPAT_FILESDIR=	${.CURDIR}/../../pkgtools/libnbcompat/files
LIBNBCOMPAT_SRCDIR=	${WRKDIR}/libnbcompat

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-I${LIBNBCOMPAT_SRCDIR}
LDFLAGS+=		-L${LIBNBCOMPAT_SRCDIR}
LIBS+=			-lnbcompat

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

PKG_DBDIR?=		/var/db/pkg
PKG_INFO=		PKG_DBDIR=${PKG_DBDIR} ${PKG_INFO_CMD}

do-extract:
	@${CP} -Rp ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_SRCDIR}
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

pre-configure:
	cd ${LIBNBCOMPAT_SRCDIR} && ./configure && ${MAKE_PROGRAM}

post-install:
	if [ ! -f ${PKG_DBDIR}/pkgdb.byfile.db ]; then			\
		if [ ! -d ${PKG_DBDIR} ]; then				\
			${INSTALL_DATA_DIR} ${PKG_DBDIR};		\
		fi;							\
		${PKG_ADMIN} rebuild;					\
	fi

.include "../../mk/bsd.pkg.mk"

PREFIX:=		${PKG_TOOLS_BIN:C|/[^/]?bin$||}
.if ${PREFIX} == "/usr"
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/man
.else
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
.endif
