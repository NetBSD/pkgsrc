# $NetBSD: Makefile,v 1.44 2001/07/24 15:02:14 wiz Exp $

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# edit PKGTOOLS_VERSION in lib/version.h to `date +%Y%m%d`, do
# "tar pzvcf pkg_install-`date +%Y%m%d`.tar.gz pkg_install" and upload
# that file to ${MASTER_SITE_LOCAL}.
# Also, modify PKGTOOLS_REQD value in pkgsrc/mk/bsd.pkg.mk
# to the new value.
DISTNAME=		pkg_install-20010724
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		NetBSD-current's pkg_* tools

# No special options needed for IPv6 support
WRKSRC=			${WRKDIR}/pkg_install
MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man NOLINT=1
NO_CONFIGURE=		yes
NO_MTREE=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"

LOCALBASE=		/usr
PKG_DBDIR?=		/var/db/pkg

.if ${OPSYS} == "NetBSD" && !exists(/usr/share/tmac/tmac.andoc)
IGNORE+=		"You need to have the 'text' set installed to build this package!"
.endif

post-install:
	if [ ! -f ${PKG_DBDIR}/pkgdb.byfile.db ]; then \
		if [ ! -d ${PKG_DBDIR} ]; then \
			${INSTALL_DATA_DIR} ${PKG_DBDIR}; \
		fi; \
		${PKG_ADMIN} rebuild ; \
	fi

.include "../../mk/bsd.pkg.mk"
