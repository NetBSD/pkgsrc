# $NetBSD: Makefile,v 1.14 2004/10/03 00:18:10 tv Exp $

DISTNAME=	krb5-1.3.4
PKGNAME=	mit-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/www/
COMMENT=	MIT Kerberos 5 authentication system

RESTRICTED=	"Redistribution is restricted by U.S. export regulations"

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

USE_MIT_KRB5_MASTER_SITE?=	yes
.if !empty(USE_MIT_KRB5_MASTER_SITE:M[yY][eE][sS])
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/1.3/
EXTRACT_SUFX=	.tar

post-extract:
	cd ${WRKDIR} && ${PAX} -O -rzf ${WRKDIR}/${DISTNAME}.tar.gz
.else
MASTER_SITES=	http://www.crypto-publish.org/dist/mit-kerberos5/ \
		http://www.mirrors.wiretapped.net/security/cryptography/apps/kerberos/krb5-mit/unix/
EXTRACT_SUFX=	.tar.gz
.endif

# Patches to fix MIT-krb5 security advisories.
MITKRB5_SA_2004_002_PATCH=	2004-002-patch_1.3.4.txt
MITKRB5_SA_2004_003_PATCH=	2004-003-patch_1.3.4.txt
.for _patch_ in ${MITKRB5_SA_2004_002_PATCH} ${MITKRB5_SA_2004_003_PATCH}
PATCHFILES+=			${_patch_}
SITES_${_patch_}=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP.${_patch_}=	-p1
PATCH_DIST_CAT.${_patch_}=	${CAT} ${_patch_}
.endfor

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
YACC=			${LOCALBASE}/bin/bison -y
.endif

USE_BUILDLINK3=		yes
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

# XXX Force using the BSD utmp interface on NetBSD until the configure
# XXX scripts can be taught how to properly detect our utmpx
# XXX implementation.
#
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_func_setutent=no
.endif

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
SUBST_FILES.mit-krb5=	include/krb5/stock/osconf.h
SUBST_SED.mit-krb5=	-e "/KRB5_PATH_RLOGIN/s,/rlogin,/${KRB5_PREFIX}rlogin,g"

INFO_FILES=	krb425.info krb5-admin.info krb5-install.info krb5-user.info

USE_PKGINSTALL=		yes
OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin info lib sbin

pre-configure:
	@cd ${WRKSRC}; ${FIND} . -name configure -print |		\
	${XARGS} -n 1 ${DIRNAME} |					\
	while read dir; do						\
		 ${ECHO} "=> Generating configure in $$dir";		\
		 (cd $$dir && ${AUTOCONF} -I ${WRKSRC} -f);		\
	done

post-install:
	cd ${WRKSRC}/../doc; for info in ${INFO_FILES}; do		\
		${INSTALL_MAN} $$info ${PREFIX}/${INFO_DIR} ;		\
		for file in $$info-[0-9]*; do				\
			if [ -f "$$file" ]; then			\
				${INSTALL_MAN} $$file ${PREFIX}/${INFO_DIR}; \
			fi;						\
		done;							\
	done

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
