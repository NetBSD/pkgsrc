# $NetBSD: Makefile,v 1.58 2002/12/20 18:15:52 schmonz Exp $

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

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		NetBSD-current's pkg_* tools

WRKSRC=			${WRKDIR}/pkg_install

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}

NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted
MANCOMPRESSED_IF_MANZ=	# defined
BUILD_DEFS+=		MANINSTALL

.include "../../mk/bsd.prefs.mk"

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

LOCALBASE:=		${PKG_TOOLS_BIN:C|/[^/]?bin$||}
PKG_DBDIR?=		/var/db/pkg

.if ${OPSYS} == "NetBSD" && !exists(/usr/share/tmac/tmac.andoc)
PKG_FAIL_REASON+= "You need to have the 'text' set installed to build this package!"
.endif

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

post-install:
	if [ ! -f ${PKG_DBDIR}/pkgdb.byfile.db ]; then \
		if [ ! -d ${PKG_DBDIR} ]; then \
			${INSTALL_DATA_DIR} ${PKG_DBDIR}; \
		fi; \
		${PKG_ADMIN} rebuild ; \
	fi

.include "../../mk/bsd.pkg.mk"
