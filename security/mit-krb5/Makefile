# $NetBSD: Makefile,v 1.52 2011/04/09 00:16:18 tez Exp $

DISTNAME=	krb5-1.8.3
PKGNAME=	mit-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/1.8/
DISTFILES=	${DISTNAME}-signed${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar

PATCH_SITES=	http://web.mit.edu/kerberos/advisories/

PATCHFILES=	2010-006-patch.txt 2010-007-patch.txt 2011-001-patch.txt 2011-002-patch-r18.txt 2011-003-patch.txt

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=	generate-files-mac all

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_TOOLS+=		autoconf perl yacc m4
USE_TOOLS+=		gmake
MAKE_PROGRAM=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR:Q}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-dns-for-realm
CONFIGURE_ARGS+=	--enable-kdc-replay-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
MAKE_ENV+=		ROOT_USER=${ROOT_USER:Q}

PATCH_DIST_ARGS=	-d ${WRKSRC} -p2

INFO_FILES=		YES

OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin include/gssapi include/gssrpc ${PKGINFODIR}	\
			${PKGMANDIR}/man1 ${PKGMANDIR}/man5		\
			${PKGMANDIR}/man8 sbin share/examples/krb5	\
			share/et share/examples/rc.d share/gnats	\
			lib/krb5/plugins/kdb lib/krb5/plugins/preauth	\
			include/krb5 include/kadm5

# The MIT krb5 distribution is actually a tar file that contains the
# real .tar.gz distfile and a PGP signature.
#
post-extract:
	@${ECHO} "=> Extracting internal tarball";			\
	extract_file="${WRKDIR}/${DISTNAME}.tar.gz";			\
	cd ${WRKDIR} && ${EXTRACT_CMD}

pre-configure:
	@${ECHO} "=> Generating configure";				\
	cd ${WRKSRC}; autoconf -I ${WRKSRC} -f;

post-install:
	@${ECHO} "=> Installing info files";				\
	cd ${WRKDIR}/${DISTNAME}/doc;					\
	for f in *.info *.info-[0-9]*; do				\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};	\
	done

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
