# $NetBSD: Makefile,v 1.71 2003/04/11 14:33:49 grant Exp $

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

USE_BUILDLINK2=		# defined

USE_DB185=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted
PKG_PRESERVE=		# defined

.include "../../mk/bsd.prefs.mk"

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

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

# db1 support is only known to work on NetBSD, so we leave it out for
# on other platforms.
.if ${OPSYS} == "NetBSD"
.  include "../../databases/db/buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"

PREFIX:=		${PKG_TOOLS_BIN:C|/[^/]?bin$||}
.if ${PREFIX} == "/usr"
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/man
.else
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
.endif
