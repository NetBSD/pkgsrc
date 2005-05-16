# $NetBSD: Makefile,v 1.21 2005/05/16 16:32:28 jlam Exp $

DISTNAME=	krb5-1.4
PKGNAME=	mit-${DISTNAME:S/-signed$//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/1.4/
DISTFILES=	${DISTNAME}-signed${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/www/
COMMENT=	MIT Kerberos 5 authentication system

RESTRICTED=	"Redistribution is restricted by U.S. export regulations"

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
YACC=			${LOCALBASE}/bin/bison -y
.endif
.endif

PKGSRC_USE_TOOLS+=	gzcat
USE_TOOLS+=		yacc
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR}

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ARGS+=	--enable-kdc-replay-cache
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--without-tcl
MAKE_ENV+=		ROOT_USER=${ROOT_USER}

.if defined(KERBEROS_PREFIX_CMDS) && !empty(KERBEROS_PREFIX_CMDS:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	prefix-cmds
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.mit-krb5
PKG_SUPPORTED_OPTIONS=	prefix-cmds
.include "../../mk/bsd.options.mk"

# Rename some of MIT krb5's applications so they won't conflict with
# other packages.
#
.if !empty(PKG_OPTIONS:Mprefix-cmds)
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
PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX}
CONFIGURE_ARGS+=	--program-transform-name="${MIT_KRB5_TRANSFORM}"

# Fix some places in the MIT krb5 sources that don't point to the correct
# Kerberized binaries when exec'ing programs.
#
SUBST_CLASSES+=		mit-krb5
SUBST_STAGE.mit-krb5=	pre-configure
SUBST_FILES.mit-krb5=	appl/bsd/Makefile.in include/krb5/stock/osconf.h
SUBST_SED.mit-krb5=	-e "/KRB5_PATH_RLOGIN/s,/rlogin,/${KRB5_PREFIX}rlogin,g"

INFO_FILES=	krb425.info krb5-admin.info krb5-install.info krb5-user.info

USE_PKGINSTALL=		yes
OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin include/gssapi include/gssrpc info lib	\
			man/man1 man/man5 man/man8 sbin			\
			share/examples/krb5

# The MIT krb5 distribution is actually a tar file that contains the
# real .tar.gz distfile and a PGP signature.
#
post-extract:
	@extract_file="${WRKDIR}/${DISTNAME}.tar.gz";			\
	cd ${WRKDIR} && ${EXTRACT_CMD}

pre-configure:
	@cd ${WRKSRC}; ${FIND} . -name configure -print |		\
	${XARGS} -n 1 ${DIRNAME} |					\
	while read dir; do						\
		 ${ECHO} "=> Generating configure in $$dir";		\
		 (cd $$dir && ${AUTOCONF} -I ${WRKSRC} -f);		\
	done

post-install:
	cd ${WRKSRC}/../doc; for i in ${INFO_FILES}; do			\
		${INSTALL_MAN} $$i ${PREFIX}/${INFO_DIR};		\
		for f in $$i-[0-9]*; do					\
			if ${TEST} -f "$$f"; then			\
				${INSTALL_MAN} "$$f" ${PREFIX}/${INFO_DIR}; \
			fi;						\
		done;							\
	done

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
