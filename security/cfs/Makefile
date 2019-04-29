# $NetBSD: Makefile,v 1.35 2019/04/29 22:24:31 gdt Exp $

DISTNAME=		cfs-1.4.1
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		https://www.mattblaze.org/software/cfs-1.4.1.tar.gz

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://www.mattblaze.org/software/
COMMENT=		Encrypting file system, using NFS as its interface

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

# Required settings necessary to build CFS on various platforms.  This is
# copied from ${WRKSRC}/Makefile and from browsing the various README files.
#
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
CFS_BUILD_SCRIPT=	${WRKSRC}/netbsd_make_with_bad_rpcgen
.elif ${OPSYS} == "SunOS"
.  if !empty(CC_VERSION:Mgcc)
CFLAGS+=		-traditional
.  endif
CFLAGS+=		-DPROTOTYPES=1
CFLAGS+=		-DSOLARIS2X -DPORTMAP -DPTMX
MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		LIBS="-lsocket -lnsl"
MAKE_ENV+=		COMPAT=
MAKE_ENV+=		RPCOPTS=
CFS_BUILD_SCRIPT=	${WRKSRC}/make_with_bad_rpcgen
.elif ${OPSYS} == "Linux"
.  if !empty(CC_VERSION:Mgcc)
CFLAGS+=		-traditional
.  endif
CFLAGS+=		-DPROTOTYPES=1
CFLAGS+=		-U__OPTIMIZE__ -U__STDC__ -Dd_fileno=d_ino
MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		LIBS=
MAKE_ENV+=		COMPAT=
MAKE_ENV+=		RPCOPTS="-k -b"
CFS_BUILD_SCRIPT=	${WRKSRC}/make_with_bad_rpcgen
.endif

CFS_SUBST_SED=		${CFS_SUBST:S/->/!/:S/$/!g/:S/^/ -e s!/}

DOCDIR=			${PREFIX}/share/doc/cfs

RCD_SCRIPTS=		cfsd

post-extract:
	@${RM} -f ${WRKSRC}/esm.1

post-patch:
	@cd ${WRKSRC}; for file in *; do				\
		${MV} -f $${file} $${file}.presubst;			\
		dest=`${ECHO} $${file} | ${SED} ${CFS_SUBST_SED}`;	\
		${SED} ${CFS_SUBST_SED} $${file}.presubst > $${dest};	\
		${RM} -f $${file}.presubst;				\
	done
	@${CHMOD} +x ${CFS_BUILD_SCRIPT}

pre-build:
	@${SED}	-e "s|@AWK@|${AWK}|g"					\
		-e "s|@MV@|${MV}|g"					\
		${FILESDIR}/unansi.sh > ${WRKSRC}/unansi
	@${CHMOD} +x ${WRKSRC}/unansi

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

.include "../../mk/bsd.pkg.mk"
