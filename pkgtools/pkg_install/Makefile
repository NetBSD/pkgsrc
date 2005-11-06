# $NetBSD: Makefile,v 1.117 2005/11/06 22:15:44 jlam Exp $

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

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}
CONFIGURE_ARGS+=	--with-ftp="\"${FETCH_CMD}"\"
CONFIGURE_ARGS+=	--with-mtree="\"${MTREE}"\"
CONFIGURE_ARGS+=	--with-pax="\"${PAX}"\"
CONFIGURE_ARGS+=	--with-tar="\"${TAR}"\"
USE_TOOLS=		mtree pax tar

# The following tools are needed by pkg_view and linkfarm.
USE_TOOLS+=		chmod cmp cp env find grep ln mkdir rm rmdir	\
			sed sort touch

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		yes
NO_MTREE=		yes
PKG_PRESERVE=		# defined
INSTALL_FILE=		${PKG_DB_TMPDIR}/+INSTALL

# These are needed to solve a chicken-and-egg problem where pkgsrc uses
# newer features of pkg_install, but older NetBSD installations won't
# support them.  In this case, we explicitly use the native GCC
# compiler to avoid problems with depending on pkgsrc GCC for building
# pkg_install.  We also avoid building digest as that would involve
# using the newer pkg_install tools.
#
# We also use the newly built pkg_delete since upgrading from an older
# pkg_install might required features of the new program.
#
USE_NATIVE_GCC=		yes
USE_DIGEST=		no
PKG_DELETE=		${WRKSRC}/delete/pkg_delete

CPPFLAGS+=		-DDEF_UMASK=${DEF_UMASK}

MAKE_ENV+=		MACHINE_ARCH="${MACHINE_ARCH}"
MAKE_ENV+=		OPSYS="${OPSYS}"

PKG_DBDIR?=		/var/db/pkg
PKG_INFO=		PKG_DBDIR=${PKG_DBDIR} ${PKG_INFO_CMD}
PKG_ADMIN=		PKG_DBDIR=${PKG_DBDIR} ${PKG_ADMIN_CMD}

PLIST_SUBST+=		PKG_DBDIR=${PKG_DBDIR}

.include "../../mk/bsd.prefs.mk"

PKG_TOOLS_PREFIX=	${PKG_TOOLS_BIN:C|/[^/]?bin$||}
VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

# XXX This breaks for those who set their own LOCALBASE to "/usr" and also
# XXX set PKGMANDIR to be other than "share/man".
# XXX
.if !empty(PKG_TOOLS_PREFIX:M/usr)
PKGMANDIR=		share/man
.endif

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

post-build:
	${SED}	-e "s|@PKG_DBDIR@|${PKG_DBDIR}|g"			\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${CHMOD} +x ${INSTALL_FILE}

pre-install-script:
	cd ${PKG_DB_TMPDIR} && ${SETENV} ${INSTALL_SCRIPTS_ENV}		\
		${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install-script:
	cd ${PKG_DB_TMPDIR} && ${SETENV} ${INSTALL_SCRIPTS_ENV}		\
		${INSTALL_FILE} ${PKGNAME} POST-INSTALL

# XXX Reverse the order that update does things since
# XXX we need pkg_delete built before we can deinstall.
# XXX This should probably be the default order for all packages.
update:
	${MAKE}
	${MAKE} deinstall UPDATE_RUNNING=YES
	${MAKE} update
	${MAKE} clean

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX:=	${PKG_TOOLS_PREFIX}
