# $NetBSD: Makefile,v 1.42 2023/03/11 01:54:01 gdt Exp $

VERSION=		1.5.0
VERSION_SUFFIX_DIST=	.beta
VERSION_SUFFIX_PKG=	b
DISTNAME=		cfs-${VERSION}${VERSION_SUFFIX_DIST}
PKGNAME=		cfs-${VERSION}${VERSION_SUFFIX_PKG}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		https://www.bayofrum.net/dist/cfs/
#OLD_MASTER_SITES=	https://www.mattblaze.org/software/cfs-1.4.1.tar.gz

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://www.mattblaze.org/software/
#HOMEPAGE+=		https://www.bayofrum.net/cgi-bin/fossil/cfs/index
COMMENT=		Encrypting file system, using NFS as its interface
# The LICENSE is clearly free, and like mit, with minor differences in
# keeping the license in derived works.  \todo Resolve.
#LICENSE=		mit-very-close

# Thanks to crees@FreeBSD.org for a continuation fork.
#  https://www.freshports.org/security/cfs/
#  https://www.bayofrum.net/cgi-bin/fossil/cfs/index

BUILD_TARGET=		cfs
INSTALL_TARGET=		install_cfs

# Avoid conflicts with coda-client's cpasswd by consistently renaming
# all references to c* to cfs_*.
#
CFS_SUBST=		cattach->cfs_attach	CATTACH->CFS_ATTACH
CFS_SUBST+=		ccat->cfs_cat		CCAT->CFS_CAT
CFS_SUBST+=		cdetach->cfs_detach	CDETACH->CFS_DETACH
CFS_SUBST+=		cmkdir->cfs_mkdir	CMKDIR->CFS_MKDIR
CFS_SUBST+=		cmkkey->cfs_mkkey	CMKKEY->CFS_MKKEY
CFS_SUBST+=		cname->cfs_name		CNAME->CFS_NAME
CFS_SUBST+=		cpasswd->cfs_passwd	CPASSWD->CFS_PASSWD

.include "../../mk/compiler.mk"
.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		OPSYS=${OPSYS:Q}

# \todo evaluate

# Required settings necessary to build CFS on various platforms.  This is
# copied from ${WRKSRC}/Makefile and from browsing the various README files.
#
# By default, we assume that the makefile is ok and we can just call it.
CFS_BUILD_SCRIPT=	do_make
.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DPROTOTYPES=1
CFLAGS+=		-DBSD44 -DANYPORT -DCFS_PORT=2049 -DSHORTLINKS
MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		COMPAT="-lcompat"
MAKE_ENV+=		RPCOPTS="-b"
#
# Use getpass() instead of own getpassword() function, which doesn't seem to
# hide the password when the user is typing it.
#
CFS_SUBST+=		getpassword->getpass
CFLAGS+=		-DHAVE_GETPASS
.elif ${OPSYS} == "SunOS"
.  if ${CC_VERSION} == gcc
# Probably this is now wrong
CFLAGS+=		-traditional
.  endif
CFLAGS+=		-DSOLARIS2X -DPORTMAP -DPTMX
MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		LIBS="-lsocket -lnsl"
MAKE_ENV+=		COMPAT=
MAKE_ENV+=		RPCOPTS=
.elif ${OPSYS} == "Linux"
.  if ${CC_VERSION} == gcc
CFLAGS+=		-traditional
.  endif
CFLAGS+=		-DPROTOTYPES=1
CFLAGS+=		-U__OPTIMIZE__ -U__STDC__ -Dd_fileno=d_ino
MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		LIBS=
MAKE_ENV+=		COMPAT=
MAKE_ENV+=		RPCOPTS="-k -b"
.endif

# Turn the list of transformations into a sed expression.
CFS_SUBST_SED=		${CFS_SUBST:S/->/!/:S/$/!g/:S/^/ -e s!/}

DOCDIR=			${PREFIX}/share/doc/cfs

RCD_SCRIPTS=		cfsd

# We install *.1 manually, because the cfs_install target doesn't
# install man pages.  However, we aren't building esm, because no one
# has made it work and it probably isn't that useful in a post-ssh
# world, so just remove the man page to avoid it being installed later.
post-extract:
	@${RM} -f ${WRKSRC}/esm.1

# Rename cfoo to cfs_foo, literally everywhere.  Use pre-configure so
# that one can "make patch" and then mkpatches without the patches
# ending up carrying this change.
pre-configure:
	@cd ${WRKSRC}; for file in *; do				\
		${MV} -f $${file} $${file}.presubst;			\
		dest=`${ECHO} $${file} | ${SED} ${CFS_SUBST_SED}`;	\
		${SED} ${CFS_SUBST_SED} $${file}.presubst > $${dest};	\
		${RM} -f $${file}.presubst;				\
	done
	# We use SH, do it doesn't need to be x
	#@${CHMOD} +x ${CFS_BUILD_SCRIPT}


# Copy our make non-wrapper script for use later.
pre-build:
	${CP} ${FILESDIR}/do_make ${WRKSRC}


do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${SH} ${CFS_BUILD_SCRIPT} ${BUILD_TARGET}

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 ${DOCDIR}

post-install:
	cd ${WRKSRC}; for file in *.1; do				\
		${INSTALL_MAN} $${file} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$${file};	\
	done
	cd ${WRKSRC}; for file in *.8; do				\
		${INSTALL_MAN} $${file} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$${file};	\
	done
	${INSTALL_DATA} ${WRKSRC}/notes.ms ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} files/README.NetBSD.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
