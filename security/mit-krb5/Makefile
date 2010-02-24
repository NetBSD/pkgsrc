# $NetBSD: Makefile,v 1.47 2010/02/24 19:07:51 tez Exp $

DISTNAME=	krb5-1.4.2
PKGNAME=	mit-${DISTNAME:S/-signed$//}
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/1.4/
DISTFILES=	${DISTNAME}-signed${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/www/
COMMENT=	MIT Kerberos 5 authentication system

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_TOOLS+=		autoconf gzcat yacc
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR:Q}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ARGS+=	--enable-kdc-replay-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--without-tcl
MAKE_ENV+=		ROOT_USER=${ROOT_USER:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.mit-krb5
PKG_SUPPORTED_OPTIONS=	kerberos-prefix-cmds

.include "../../mk/bsd.options.mk"

# Rename some of MIT krb5's applications so they won't conflict with
# other packages.
#
.if !empty(PKG_OPTIONS:Mkerberos-prefix-cmds)
KRB5_PREFIX=		k
MIT_KRB5_TRANSFORM=	s/^ftp/${KRB5_PREFIX}&/;			\
			s/^rcp/${KRB5_PREFIX}&/;			\
			s/^rlogin/${KRB5_PREFIX}&/;			\
			s/^rsh/${KRB5_PREFIX}&/;			\
			s/^telnet/${KRB5_PREFIX}&/
.else
KRB5_PREFIX=		# empty
MIT_KRB5_TRANSFORM=	s/^ftp/k&/
.endif
PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX:Q}
CONFIGURE_ARGS+=	--program-transform-name=${MIT_KRB5_TRANSFORM:Q}

# Fix some places in the MIT krb5 sources that don't point to the correct
# Kerberized binaries when exec'ing programs.
#
SUBST_CLASSES+=		mit-krb5
SUBST_STAGE.mit-krb5=	pre-configure
SUBST_FILES.mit-krb5=	appl/bsd/Makefile.in include/krb5/stock/osconf.h
SUBST_SED.mit-krb5=	-e "/KRB5_PATH_RLOGIN/s,/rlogin,/${KRB5_PREFIX}rlogin,g"

# Fix autoconf incompatibility in new versions where substitutions won't be
# processed properly.  For more details see:
#  http://mailman.mit.edu/pipermail/krb5-bugs/2006-June/004587.html
SUBST_CLASSES+=		frag
SUBST_STAGE.frag=	post-patch
SUBST_FILES.frag=	appl/telnet/libtelnet/Makefile.in	\
			lib/apputils/Makefile.in		\
			lib/crypto/Makefile.in			\
			lib/crypto/aes/Makefile.in		\
			lib/crypto/arcfour/Makefile.in		\
			lib/crypto/crc32/Makefile.in		\
			lib/crypto/des/Makefile.in		\
			lib/crypto/dk/Makefile.in		\
			lib/crypto/enc_provider/Makefile.in	\
			lib/crypto/hash_provider/Makefile.in	\
			lib/crypto/keyhash_provider/Makefile.in	\
			lib/crypto/md4/Makefile.in		\
			lib/crypto/md5/Makefile.in		\
			lib/crypto/old/Makefile.in		\
			lib/crypto/raw/Makefile.in		\
			lib/crypto/sha1/Makefile.in		\
			lib/crypto/yarrow/Makefile.in		\
			lib/des425/Makefile.in			\
			lib/gssapi/Makefile.in			\
			lib/gssapi/generic/Makefile.in		\
			lib/gssapi/krb5/Makefile.in		\
			lib/kadm5/Makefile.in			\
			lib/kadm5/clnt/Makefile.in		\
			lib/kadm5/srv/Makefile.in		\
			lib/kdb/Makefile.in			\
			lib/krb4/Makefile.in			\
			lib/krb5/Makefile.in			\
			lib/krb5/asn.1/Makefile.in		\
			lib/krb5/ccache/Makefile.in		\
			lib/krb5/error_tables/Makefile.in	\
			lib/krb5/keytab/Makefile.in		\
			lib/krb5/krb/Makefile.in		\
			lib/krb5/os/Makefile.in			\
			lib/krb5/posix/Makefile.in		\
			lib/krb5/rcache/Makefile.in		\
			lib/rpc/Makefile.in			\
			util/db2/Makefile.in			\
			util/db2/btree/Makefile.in		\
			util/db2/clib/Makefile.in		\
			util/db2/db/Makefile.in			\
			util/db2/hash/Makefile.in		\
			util/db2/mpool/Makefile.in		\
			util/db2/recno/Makefile.in		\
			util/et/Makefile.in			\
			util/profile/Makefile.in		\
			util/pty/Makefile.in			\
			util/ss/Makefile.in			\
			util/support/Makefile.in
SUBST_SED.frag=		-e "s/^\#.\\(@lib.*_frag@\\)/\\1/g"

INFO_FILES=		# PLIST

OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin include/gssapi include/gssrpc ${PKGINFODIR}	\
			lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5		\
			${PKGMANDIR}/man8 sbin share/examples/krb5

# The MIT krb5 distribution is actually a tar file that contains the
# real .tar.gz distfile and a PGP signature.
#
post-extract:
	extract_file="${WRKDIR}/${DISTNAME}.tar.gz";			\
	cd ${WRKDIR} && ${EXTRACT_CMD}

pre-configure:
	cd ${WRKSRC}; ${FIND} . -name configure -print |		\
	${XARGS} -n 1 ${DIRNAME} |					\
	while read dir; do						\
		 ${ECHO} "=> Generating configure in $$dir";		\
		 (cd $$dir && autoconf -I ${WRKSRC} -f);		\
	done

post-install:
	cd ${WRKSRC}/../doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
