# $NetBSD: Makefile,v 1.112 2005/05/16 00:09:33 jlam Exp $

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
COMMENT=		Package management and administration tools for pkgsrc

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}
CONFIGURE_ARGS+=	--with-ftp="\"${FETCH_CMD}"\"
CONFIGURE_ARGS+=	--with-mtree="\"${MTREE}"\"
CONFIGURE_ARGS+=	--with-pax="\"${PAX}"\"
CONFIGURE_ARGS+=	--with-tar="\"${TAR}"\"
USE_TOOLS=		mtree pax tar

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
PKG_PRESERVE=		# defined

# These are needed to solve a chicken-and-egg problem where pkgsrc uses
# newer features of pkg_install, but older NetBSD installations won't
# support them.  In this case, we explicitly use the native GCC
# compiler to avoid problems with depending on pkgsrc GCC for building
# pkg_install.  We also avoid building digest as that would involve
# using the newer pkg_install tools.
# We also use the newly built pkg_delete since upgrading from
# an older pkg_install might required features of the new program.
#
USE_NATIVE_GCC=		yes
USE_DIGEST=		no
PKG_DELETE=	${WRKSRC}/delete/pkg_delete

PLIST_SUBST+=		MANDIR=${MANDIR}
PLIST_SUBST+=		PKG_TOOLS_BIN=${PKG_TOOLS_BIN}

CPPFLAGS+=		-DDEF_UMASK=${DEF_UMASK}

MAKE_ENV+=		MACHINE_ARCH="${MACHINE_ARCH}"
MAKE_ENV+=		OPSYS="${OPSYS}"

PKG_DBDIR?=		/var/db/pkg
PKG_INFO=		PKG_DBDIR=${PKG_DBDIR} ${PKG_INFO_CMD}
PKG_ADMIN=		PKG_DBDIR=${PKG_DBDIR} ${PKG_ADMIN_CMD}

.include "../../mk/bsd.prefs.mk"

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

post-install:
	if [ ! -f ${PKG_DBDIR}/pkgdb.byfile.db ]; then			\
		if [ ! -d ${PKG_DBDIR} ]; then				\
			${INSTALL_DATA_DIR} ${PKG_DBDIR};		\
		fi;							\
		${PKG_ADMIN} rebuild;					\
	fi

# XXX Reverse the order that update does things since
# XXX we need pkg_delete built before we can deinstall.
# XXX This should probably be the default order for all packages.
update:
	${MAKE}
	${MAKE} deinstall UPDATE_RUNNING=YES
	${MAKE} install
	${MAKE} clean

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX:=		${PKG_TOOLS_BIN:C|/[^/]?bin$||}
.if ${PREFIX} == "/usr"
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/man
MANDIR=			share/
.else
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
MANDIR=			# empty
.endif
