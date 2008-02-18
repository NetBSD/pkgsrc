# $NetBSD: Makefile,v 1.28 2008/02/18 20:26:33 jlam Exp $

.include "Makefile.common"

DISTNAME=	courier-authlib-0.60.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Courier Authentication Library
HOMEPAGE=	http://www.courier-mta.org/authlib/

CONFLICTS+=	courier-auth-[0-9]*
CONFLICTS+=	courier-authldap-[0-9]*
CONFLICTS+=	courier-authmysql-[0-9]*
CONFLICTS+=	courier-authpgsql-[0-9]*

#LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKG_SYSCONFSUBDIR=	authlib

REPLACE_PERL=		samplepipe.pl sysconftool

USE_LANGUAGES=		c c++
USE_TOOLS+=		cat:run gmake perl:run
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}		# makedat

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--without-stdheaderdir

AUTHDAEMONVAR?=		${VARBASE}/authdaemon
CONFIGURE_ARGS+=	--with-authdaemonvar=${AUTHDAEMONVAR:Q}
OWN_DIRS_PERMS=		${AUTHDAEMONVAR} ${COURIER_USER} ${COURIER_GROUP} 0750
FILES_SUBST+=		AUTHDAEMONVAR=${AUTHDAEMONVAR:Q}

# Expect is used to change the password from within the courier webmail
# application (sqwebmail).  Assume that it's installed in the same prefix
# as courier-authlib.
#
CONFIGURE_ENV+=		EXPECT=${PREFIX:Q}/bin/expect
CHECK_INTERPRETER_SKIP=	libexec/courier-authlib/authsystem.passwd

AUTHLIBDIR=		lib/courier-authlib
AUTHLIBEXECDIR=		libexec/courier-authlib
AUTHEXAMPLEDIR=		share/examples/courier-authlib
AUTHDOCDIR=		share/doc/courier-authlib
FILES_SUBST+=		AUTHLIBEXECDIR=${AUTHLIBEXECDIR:Q}
FILES_SUBST+=		AUTHEXAMPLEDIR=${AUTHEXAMPLEDIR:Q}

PKG_SYSCONFSUBDIR?=	courier

EGDIR=			${PREFIX}/${AUTHEXAMPLEDIR}
DOCDIR=			${PREFIX}/${AUTHDOCDIR}
RCD_SCRIPTS=		authdaemond
GEN_FILES=		authdaemonrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
AUTHLIB_PLIST=		${AUTHEXAMPLEDIR}/authdaemonrc.dist

# Install the example config files into ${EGDIR}.
INSTALL_AM_MAKEFLAGS=	authdaemonrc=${EGDIR}/authdaemonrc		\
			authldaprc=${EGDIR}/authldaprc			\
			authmysqlrc=${EGDIR}/authmysqlrc		\
			authpgsqlrc=${EGDIR}/authpgsqlrc
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

POST_INSTALL_TARGETS=	post-install-common post-install-authdaemon

.include "options.mk"
.include "../../devel/libltdl/buildlink3.mk"

.for _file_ in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${_file_}.dist ${PKG_SYSCONFDIR}/${_file_} \
			${COURIER_USER} ${COURIER_GROUP} 0660
.endfor

.for _file_ in ${AUTHLIB_PLIST}
GENERATE_PLIST+=	${TEST} -f ${DESTDIR}${PREFIX}/${_file_} &&	\
			${ECHO} "${_file_}";
.endfor
.if !empty(AUTHLIB_PLIST:M${AUTHEXAMPLEDIR}/*)
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHEXAMPLEDIR}";
.endif
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHDOCDIR}";
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHLIBEXECDIR}";
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHLIBDIR}";

INSTALLATION_DIRS=	bin sbin

post-install: ${POST_INSTALL_TARGETS}

post-install-common:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.authdebug.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README_authlib.html ${DESTDIR}${DOCDIR}

post-install-authdaemon:
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${EGDIR}/authdaemonrc.dist
	${CHMOD} ${SHAREMODE} ${DESTDIR}${EGDIR}/authdaemonrc.dist

.include "../../mk/bsd.pkg.mk"
