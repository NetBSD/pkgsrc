# $NetBSD: Makefile,v 1.63 2012/12/22 02:27:56 joerg Exp $

DISTNAME=	krb5-1.10.3
PKGNAME=	mit-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar
DISTFILES=	${DISTNAME}-signed${EXTRACT_SUFX}

#PATCH_SITES=	http://web.mit.edu/kerberos/advisories/
#PATCHFILES=	2011-006-patch-r18.txt

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=	generate-files-mac all

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake m4 perl yacc msgfmt
MAKE_PROGRAM=		gmake
GNU_CONFIGURE=		yes

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-dns-for-realm
CONFIGURE_ARGS+=	--enable-kdc-replay-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
MAKE_ENV+=		ROOT_USER=${ROOT_USER}

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
