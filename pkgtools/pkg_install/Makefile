# $NetBSD: Makefile,v 1.130.4.1 2007/07/21 01:19:08 salo Exp $

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

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Package management and administration tools for pkgsrc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR:Q}
CONFIGURE_ARGS+=	--with-ftp="\"${FETCH_CMD}"\"
CONFIGURE_ARGS+=	--with-mtree="\"${MTREE}"\"
CONFIGURE_ARGS+=	--with-pax="\"${PAX}"\"
CONFIGURE_ARGS+=	--with-tar="\"${TAR}"\"
USE_TOOLS+=		mtree pax tar

# The following tools are needed by pkg_view and linkfarm.
USE_TOOLS+=		chmod cmp cp env find grep ln mkdir rm rmdir	\
			sed sort touch

SKIP_AUDIT_PACKAGES=	yes
NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
PKG_PRESERVE=		yes

# These are needed to solve a chicken-and-egg problem where pkgsrc uses
# newer features of pkg_install, but older NetBSD installations won't
# support them.  In this case, we explicitly use the native GCC
# compiler to avoid problems with depending on pkgsrc GCC for building
# pkg_install.
#
# We also use the newly built pkg_delete since upgrading from an older
# pkg_install might required features of the new program.
#
USE_NATIVE_GCC=		yes
PKG_DELETE=		${WRKSRC}/delete/pkg_delete

CPPFLAGS+=		-DDEF_UMASK=${DEF_UMASK}

MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
MAKE_ENV+=		OPSYS=${OPSYS:Q}

PKG_DBDIR?=		/var/db/pkg
PKG_INFO=		PKG_DBDIR=${PKG_DBDIR:Q} ${PKG_INFO_CMD}
PKG_ADMIN=		PKG_DBDIR=${PKG_DBDIR:Q} ${PKG_ADMIN_CMD}

PLIST_SUBST+=		PKG_DBDIR=${PKG_DBDIR:Q}

DEINSTALL_SRC=		# empty
INSTALL_SRC=		${PKGDIR}/INSTALL
FILES_SUBST+=		PKG_DBDIR=${PKG_DBDIR:Q}			\
			PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}		\
			MKDIR=${MKDIR:Q}

.include "../../mk/bsd.prefs.mk"

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

# XXX Reverse the order that update does things since
# XXX we need pkg_delete built before we can deinstall.
# XXX This should probably be the default order for all packages.
update:
	${MAKE}
	${MAKE} deinstall _UPDATE_RUNNING=YES
	${MAKE} ${UPDATE_TARGET}
	${MAKE} clean

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"
